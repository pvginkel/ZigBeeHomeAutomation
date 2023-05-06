const fz = require("zigbee-herdsman-converters/converters/fromZigbee");
const tz = require("zigbee-herdsman-converters/converters/toZigbee");
const exposes = require("zigbee-herdsman-converters/lib/exposes");
const reporting = require("zigbee-herdsman-converters/lib/reporting");
const extend = require("zigbee-herdsman-converters/lib/extend");
const { getKey } = require("zigbee-herdsman-converters/lib/utils");
const e = exposes.presets;
const ea = exposes.access;

const fzLocal = {
  doorbell_configuration: {
    cluster: "genOnOff",
    type: ["attributeReport", "readResponse"],
    convert: (model, msg, publish, options, meta) => {
      const readValue = (attribute, name) => {
        if (msg.data.hasOwnProperty(attribute)) {
          result[name] = msg.data[attribute];
        }
      };

      const result = {};
      readValue(0x0201, "doorbell_enabled");
      return result;
    },
  },
};

const tzLocal = {
  doorbell_enabled: {
    key: ["doorbell_enabled"],
    convertSet: async (entity, key, value, meta) => {
      await entity.write("genOnOff", { 0x0201: { value, type: 0x10 } });
      return { state: { doorbell_enabled: !!value } };
    },
    convertGet: async (entity, key, meta) => {
      await entity.read("genOnOff", [0x0201]);
    },
  },
};

const eLocal = {
  doorbell_enabled: () => {
    return exposes
      .binary("doorbell_enabled", ea.GET | ea.SET)
      .withDescription("Enable doorbell");
  },
};

const extendLocal = {
  switch: (options = {}) => ({
    ...extend.switch(options),
    fromZigbee: [
      ...extend.switch(options).fromZigbee,
      fz.command_on,
      fzLocal.doorbell_configuration,
    ],
    toZigbee: [...extend.switch(options).toZigbee, tzLocal.doorbell_enabled],
    exposes: [
      ...extend.switch(options).exposes,
      e.action(["on"]),
      eLocal.doorbell_enabled(),
    ],
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
