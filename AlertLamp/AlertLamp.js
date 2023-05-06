const fz = require("zigbee-herdsman-converters/converters/fromZigbee");
const tz = require("zigbee-herdsman-converters/converters/toZigbee");
const exposes = require("zigbee-herdsman-converters/lib/exposes");
const reporting = require("zigbee-herdsman-converters/lib/reporting");
const extend = require("zigbee-herdsman-converters/lib/extend");
const { getKey } = require("zigbee-herdsman-converters/lib/utils");
const e = exposes.presets;
const ea = exposes.access;

const fzLocal = {
  alert_light_configuration: {
    cluster: "genOnOff",
    type: ["attributeReport", "readResponse"],
    convert: (model, msg, publish, options, meta) => {
      const readValue = (attribute, name) => {
        if (msg.data.hasOwnProperty(attribute)) {
          result[name] = msg.data[attribute];
        }
      };

      const result = {};
      readValue(0x0201, "alert_light_seconds_on");
      return result;
    },
  },
};

const tzLocal = {
  alert_light_seconds_on: {
    key: ["alert_light_seconds_on"],
    convertSet: async (entity, key, value, meta) => {
      await entity.write("genOnOff", { 0x0201: { value, type: 0x21 } });
      return { state: { alert_light_seconds_on: value } };
    },
    convertGet: async (entity, key, meta) => {
      await entity.read("genOnOff", [0x0201]);
    },
  },
};

const eLocal = {
  alert_light_seconds_on: () => {
    return exposes
      .numeric("alert_light_seconds_on", ea.GET | ea.SET)
      .withDescription("Number of seconds the alert lamp stays on");
  },
};

const extendLocal = {
  switch: (options = {}) => ({
    ...extend.switch(options),
    fromZigbee: [
      ...extend.switch(options).fromZigbee,
      fzLocal.alert_light_configuration,
    ],
    toZigbee: [
      ...extend.switch(options).toZigbee,
      tzLocal.alert_light_seconds_on,
    ],
    exposes: [
      ...extend.switch(options).exposes,
      eLocal.alert_light_seconds_on(),
    ],
  }),
};

const definition = {
  zigbeeModel: ["Alert Lamp"],
  model: "Alert Lamp",
  vendor: "Pieter",
  description: "Alert lamp",
  extend: extendLocal.switch(),
};

module.exports = definition;
