const fz = require("zigbee-herdsman-converters/converters/fromZigbee");
const tz = require("zigbee-herdsman-converters/converters/toZigbee");
const exposes = require("zigbee-herdsman-converters/lib/exposes");
const reporting = require("zigbee-herdsman-converters/lib/reporting");
const extend = require("zigbee-herdsman-converters/lib/extend");
const { getKey } = require("zigbee-herdsman-converters/lib/utils");
const e = exposes.presets;
const ea = exposes.access;

const extendLocal = {
  switch: (options = {}) => ({
    ...extend.switch(options),
    fromZigbee: [...extend.switch(options).fromZigbee, fz.command_on],
    toZigbee: [...extend.switch(options).toZigbee],
    exposes: [...extend.switch(options).exposes, e.action(["on"])],
  }),
};

const definition = {
  zigbeeModel: ["Doorbell"],
  model: "Doorbell",
  vendor: "Pieter",
  description: "Doorbell",
  extend: extendLocal.switch(),
};

module.exports = definition;
