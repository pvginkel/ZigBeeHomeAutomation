const fz = require("zigbee-herdsman-converters/converters/fromZigbee");
const tz = require("zigbee-herdsman-converters/converters/toZigbee");
const exposes = require("zigbee-herdsman-converters/lib/exposes");
const reporting = require("zigbee-herdsman-converters/lib/reporting");
const extend = require("zigbee-herdsman-converters/lib/extend");
const e = exposes.presets;
const ea = exposes.access;

const fzLocal = {
  logging: {
    cluster: "genBasic",
    type: ["attributeReport", "readResponse"],
    convert: (model, msg, publish, options, meta) => {
      const readValue = (attribute, name) => {
        if (msg.data.hasOwnProperty(attribute)) {
          result[name] = msg.data[attribute];
        }
      };

      const result = {};
      readValue(0x0201, "log");
      return result;
    },
  },
};

const eLocal = {
  log: () => {
    return exposes.text("log", ea.STATE).withDescription("Log message");
  },
};

const definition = {
  zigbeeModel: ["Thermostat Proxy"],
  model: "Thermostat Proxy",
  vendor: "Pieter",
  description: "Logging thermostat proxy",
  fromZigbee: [fzLocal.logging],
  toZigbee: [],
  exposes: [eLocal.log()],
  configure: async (device, coordinatorEndpoint, logger) => {},
};

module.exports = definition;
