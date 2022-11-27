const fz = require("zigbee-herdsman-converters/converters/fromZigbee");
const tz = require("zigbee-herdsman-converters/converters/toZigbee");
const exposes = require("zigbee-herdsman-converters/lib/exposes");
const reporting = require("zigbee-herdsman-converters/lib/reporting");
const extend = require("zigbee-herdsman-converters/lib/extend");
const e = exposes.presets;
const ea = exposes.access;

const definition = {
  zigbeeModel: ["The Big Clock"],
  model: "The Big Clock",
  vendor: "Pieter",
  description: "The Big Clock",
  extend: extend.switch(),
};

module.exports = definition;
