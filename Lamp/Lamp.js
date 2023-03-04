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
    convert: (model, msg, publish, options, meta) => {
      const readValue = (attribute, name) => {
        if (msg.data.hasOwnProperty(attribute)) {
          result[name] = msg.data[attribute];
        }
      };

      const result = {};
      readValue(0x0201, "light_minimum_level");
      readValue(0x0202, "light_maximum_level");
      return result;
    },
  },
};

const tzLocal = {
  light_minimum_level: {
    key: ["light_minimum_level"],
    convertSet: async (entity, key, value, meta) => {
      await entity.write('genLevelCtrl', { 0x0201: { value, type: 0x20 } });
      return { state: { light_minimum_level: value }};
    },
    convertGet: async (entity, key, meta) => {
      await entity.read('genLevelCtrl', [0x0201]);
    },
  },
  light_maximum_level: {
    key: ["light_maximum_level"],
    convertSet: async (entity, key, value, meta) => {
      await entity.write('genLevelCtrl', { 0x0202: { value, type: 0x20 } });
      return { state: { light_maximum_level: value }};
    },
    convertGet: async (entity, key, meta) => {
      await entity.read('genLevelCtrl', [0x0202]);
    },
  },
};

const eLocal = {
  light_minimum_level: () => {
    return exposes
      .numeric("light_minimum_level", ea.GET | ea.SET)
      .withDescription("Light minimum level")
  },
  light_maximum_level: () => {
    return exposes
      .numeric("light_maximum_level", ea.GET | ea.SET)
      .withDescription("Light maximum level");
  },
};

const extendLocal = {
  light_onoff_brightness: (options={}) => ({
    ...extend.light_onoff_brightness(options),
    fromZigbee: [...extend.light_onoff_brightness(options).fromZigbee, fzLocal.light_configuration],
    toZigbee: [...extend.light_onoff_brightness(options).toZigbee,
      tzLocal.light_minimum_level, tzLocal.light_maximum_level
    ],
    exposes: [...extend.light_onoff_brightness(options).exposes,
      eLocal.light_minimum_level(), eLocal.light_maximum_level()]
  }),
};

const definition = {
  zigbeeModel: ["Lamp"],
  model: "Lamp",
  vendor: "Pieter",
  description: "Dimmable lamp",
  extend: extendLocal.light_onoff_brightness(),
};

module.exports = definition;
