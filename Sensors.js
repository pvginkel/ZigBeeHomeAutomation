const fz = require("zigbee-herdsman-converters/converters/fromZigbee");
const tz = require("zigbee-herdsman-converters/converters/toZigbee");
const exposes = require("zigbee-herdsman-converters/lib/exposes");
const reporting = require("zigbee-herdsman-converters/lib/reporting");
const extend = require("zigbee-herdsman-converters/lib/extend");
const e = exposes.presets;
const ea = exposes.access;

const fzLocal = {
  illuminance_33k: {
    cluster: "msIlluminanceMeasurement",
    type: ["attributeReport", "readResponse"],
    options: [
      exposes.options.calibration("illuminance_33k", "percentual"),
      exposes.options.calibration("illuminance_33k_lux", "percentual"),
    ],
    convert: (model, msg, publish, options, meta) => {
      // DEPRECATED: only return lux here (change illuminance_lux -> illuminance)
      const illuminance = msg.data["measuredValue"];
      const illuminanceLux =
        illuminance === 0 ? 0 : Math.pow(10, (illuminance - 1) / 10000);
      return {
        illuminance: calibrateAndPrecisionRoundOptions(
          illuminance,
          options,
          "illuminance_33k"
        ),
        illuminance_lux: calibrateAndPrecisionRoundOptions(
          illuminanceLux,
          options,
          "illuminance_33k_lux"
        ),
      };
    },
  },
  illuminance_60k: {
    cluster: "msIlluminanceMeasurement",
    type: ["attributeReport", "readResponse"],
    options: [
      exposes.options.calibration("illuminance_60k", "percentual"),
      exposes.options.calibration("illuminance_60k_lux", "percentual"),
    ],
    convert: (model, msg, publish, options, meta) => {
      // DEPRECATED: only return lux here (change illuminance_lux -> illuminance)
      const illuminance = msg.data["measuredValue"];
      const illuminanceLux =
        illuminance === 0 ? 0 : Math.pow(10, (illuminance - 1) / 10000);
      return {
        illuminance: calibrateAndPrecisionRoundOptions(
          illuminance,
          options,
          "illuminance_60k"
        ),
        illuminance_lux: calibrateAndPrecisionRoundOptions(
          illuminanceLux,
          options,
          "illuminance_60k_lux"
        ),
      };
    },
  },
  illuminance_200k: {
    cluster: "msIlluminanceMeasurement",
    type: ["attributeReport", "readResponse"],
    options: [
      exposes.options.calibration("illuminance_200k", "percentual"),
      exposes.options.calibration("illuminance_200k_lux", "percentual"),
    ],
    convert: (model, msg, publish, options, meta) => {
      // DEPRECATED: only return lux here (change illuminance_lux -> illuminance)
      const illuminance = msg.data["measuredValue"];
      const illuminanceLux =
        illuminance === 0 ? 0 : Math.pow(10, (illuminance - 1) / 10000);
      return {
        illuminance: calibrateAndPrecisionRoundOptions(
          illuminance,
          options,
          "illuminance_200k"
        ),
        illuminance_lux: calibrateAndPrecisionRoundOptions(
          illuminanceLux,
          options,
          "illuminance_200k_lux"
        ),
      };
    },
  },
};

const eLocal = {
  illuminance_33k: () =>
    new Numeric("illuminance_33k", access.STATE).withDescription(
      "Raw measured illuminance of 33K photo resistor"
    ),
  illuminance_33k_lux: () =>
    new Numeric("illuminance_33k_lux", access.STATE)
      .withUnit("lx")
      .withDescription("Measured illuminance in lux of 33K photo resistor"),
  illuminance_60k: () =>
    new Numeric("illuminance_60k", access.STATE).withDescription(
      "Raw measured illuminance of 60K photo resistor"
    ),
  illuminance_60k_lux: () =>
    new Numeric("illuminance_60k_lux", access.STATE)
      .withUnit("lx")
      .withDescription("Measured illuminance in lux of 60K photo resistor"),
  illuminance_200k: () =>
    new Numeric("illuminance_200k", access.STATE).withDescription(
      "Raw measured illuminance of 200K photo resistor"
    ),
  illuminance_200k_lux: () =>
    new Numeric("illuminance_200k_lux", access.STATE)
      .withUnit("lx")
      .withDescription("Measured illuminance in lux of 200K photo resistor"),
};

const definition = {
  zigbeeModel: ["Sensors"],
  model: "Sensors",
  vendor: "Pieter",
  description: "Temperature and humidity sensors",
  fromZigbee: [
    fz.temperature,
    fz.humidity,
    fzLocal.illuminance_33k,
    fzLocal.illuminance_60k,
    fzLocal.illuminance_200k,
  ],
  toZigbee: [],
  exposes: [
    e.temperature(),
    e.humidity(),
    eLocal.illuminance_33k(),
    eLocal.illuminance_33k_lux(),
    eLocal.illuminance_60k(),
    eLocal.illuminance_60k_lux(),
    eLocal.illuminance_200k(),
    eLocal.illuminance_200k_lux(),
  ],
  configure: async (device, coordinatorEndpoint, logger) => {
    const endpoint2 = device.getEndpoint(2);
    await reporting.bind(endpoint2, coordinatorEndpoint, [
      "msIlluminanceMeasurement",
    ]);
  },
};

module.exports = definition;
