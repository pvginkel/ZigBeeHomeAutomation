const fz = require("zigbee-herdsman-converters/converters/fromZigbee");
const tz = require("zigbee-herdsman-converters/converters/toZigbee");
const exposes = require("zigbee-herdsman-converters/lib/exposes");
const reporting = require("zigbee-herdsman-converters/lib/reporting");
const extend = require("zigbee-herdsman-converters/lib/extend");
const utils = require("zigbee-herdsman-converters/lib/utils");
const e = exposes.presets;
const ea = exposes.access;

const fzLocal = {
  illuminance: {
    cluster: "msIlluminanceMeasurement",
    type: ["attributeReport", "readResponse"],
    options: [
      exposes.options.calibration("illuminance", "percentual"),
      exposes.options.calibration("illuminance_lux", "percentual"),
    ],
    convert: (model, msg, publish, options, meta) => {
      const result = {};

      if (msg.data.hasOwnProperty("measuredValue")) {
        const raw = msg.data["measuredValue"];
        const VIN = 5.0;
        const R = 10000;

        // Conversion analog to voltage
        const Vout = raw * (VIN / 1023);
        // Conversion voltage to resistance
        const RLDR = (R * (VIN - Vout)) / Vout;
        // Conversion resitance to lumen
        const phys = 500 / (RLDR / 1000);

        result[utils.postfixWithEndpointName("illuminance", msg, model, meta)] =
          RLDR | 0;
        result[
          utils.postfixWithEndpointName("illuminance_lux", msg, model, meta)
        ] = phys | 0;
      }

      return result;
    },
  },

  filteredTemperature: {
    ...fz.temperature,
    convert: (model, msg, publish, options, meta) => {
      if (msg.data.measuredValue != 0) {
          return fz.temperature.convert(model, msg, publish, options, meta);
      }
    }
  },

  filteredHumidity: {
    ...fz.humidity,
    convert: (model, msg, publish, options, meta) => {
      if (msg.data.measuredValue != 0) {
          return fz.humidity.convert(model, msg, publish, options, meta);
      }
    }
  }
};

const definition = {
  zigbeeModel: ["Sensors"],
  model: "Sensors",
  vendor: "Pieter",
  description: "Temperature, humidity and photoresistor sensors",
  fromZigbee: [fzLocal.filteredTemperature, fzLocal.filteredHumidity, fzLocal.illuminance],
  toZigbee: [],
  meta: { multiEndpoint: true },
  exposes: [
    e.temperature(),
    e.humidity(),
    e.illuminance().withEndpoint("33k"),
    e.illuminance_lux().withEndpoint("33k"),
    e.illuminance().withEndpoint("60k"),
    e.illuminance_lux().withEndpoint("60k"),
    e.illuminance().withEndpoint("200k"),
    e.illuminance_lux().withEndpoint("200k"),
  ],
  endpoint: (device) => {
    return { "33k": 2, "60k": 3, "200k": 4 };
  },
  configure: async (device, coordinatorEndpoint, logger) => {
    const endpoint = device.getEndpoint(1);
    const endpoint33k = device.getEndpoint(2);
    const endpoint60k = device.getEndpoint(3);
    const endpoint200k = device.getEndpoint(4);

    await reporting.bind(endpoint, coordinatorEndpoint, [
      "msTemperatureMeasurement",
      "msSoilMoisture",
    ]);

    const createReport = (attribute) => {
      return {
        attribute: attribute,
        minimumReportInterval: 1,
        maximumReportInterval: 3600,
        // This fails when using custom attributes.
        // reportableChange: 0,
      };
    };

    const msTemperatureMeasurementReporting = [createReport("measuredValue")];
    await endpoint.configureReporting(
      "msTemperatureMeasurement",
      msTemperatureMeasurementReporting
    );

    const msRelativeHumidityReporting = [createReport("measuredValue")];
    await endpoint.configureReporting(
      "msRelativeHumidity",
      msRelativeHumidityReporting
    );

    const msIlluminanceMeasurementReporting = [createReport("measuredValue")];
    await endpoint33k.configureReporting(
      "msIlluminanceMeasurement",
      msIlluminanceMeasurementReporting
    );
    await endpoint60k.configureReporting(
      "msIlluminanceMeasurement",
      msIlluminanceMeasurementReporting
    );
    await endpoint200k.configureReporting(
      "msIlluminanceMeasurement",
      msIlluminanceMeasurementReporting
    );
  },
  onEvent: async (type, data, device, options, state) => {
    /**
     * The Arduino isn't storing reporting configuration. We use the announce
     * event to send the reporting configuration again.
     */
    if (type === "deviceAnnounce") {
      for (const endpoint of device.endpoints) {
        for (const c of endpoint.configuredReportings) {
          await endpoint.configureReporting(c.cluster.name, [
            {
              attribute: c.attribute.name,
              minimumReportInterval: c.minimumReportInterval,
              maximumReportInterval: c.maximumReportInterval,
              reportableChange: c.reportableChange,
            },
          ]);
        }
      }
    }
  },
};

module.exports = definition;
