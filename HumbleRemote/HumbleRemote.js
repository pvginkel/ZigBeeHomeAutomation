const fz = require("zigbee-herdsman-converters/converters/fromZigbee");
const tz = require("zigbee-herdsman-converters/converters/toZigbee");
const exposes = require("zigbee-herdsman-converters/lib/exposes");
const reporting = require("zigbee-herdsman-converters/lib/reporting");
const extend = require("zigbee-herdsman-converters/lib/extend");
const { getKey } = require("zigbee-herdsman-converters/lib/utils");
const e = exposes.presets;
const ea = exposes.access;

const fzLocal = {
  light_configuration: {
    cluster: "genLevelCtrl",
    type: ["attributeReport", "readResponse"],
  },
};

const tzLocal = {};

const eLocal = {};

const extendLocal = {
  light_onoff_brightness: (options = {}) => ({
    ...extend.light_onoff_brightness(options),
    fromZigbee: [...extend.light_onoff_brightness(options).fromZigbee],
    toZigbee: [...extend.light_onoff_brightness(options).toZigbee],
    exposes: [...extend.light_onoff_brightness(options).exposes],
  }),
};

const definition = {
  zigbeeModel: ["Humble Remote"],
  model: "Humble Remote",
  vendor: "Pieter",
  description: "Remote for Humble lamps",
  extend: extend.light_onoff_brightness(),
};

module.exports = definition;
