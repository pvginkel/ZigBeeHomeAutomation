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
      readValue(0x0201, "light_low_minimum_level");
      readValue(0x0202, "light_low_maximum_level");
      readValue(0x0203, "light_high_minimum_level");
      readValue(0x0204, "light_high_maximum_level");
      readValue(0x0205, "light_break_start");
      readValue(0x0206, "light_break_end");
      return result;
    },
  },
};

const tzLocal = {
  light_low_minimum_level: {
    key: ["light_low_minimum_level"],
    convertSet: async (entity, key, value, meta) => {
      await entity.write('genLevelCtrl', { 0x0201: { value, type: 0x20 } });
      return { state: { light_low_minimum_level: value }};
    },
    convertGet: async (entity, key, meta) => {
      await entity.read('genLevelCtrl', [0x0201]);
    },
  },
  light_low_maximum_level: {
    key: ["light_low_maximum_level"],
    convertSet: async (entity, key, value, meta) => {
      await entity.write('genLevelCtrl', { 0x0202: { value, type: 0x20 } });
      return { state: { light_low_maximum_level: value }};
    },
    convertGet: async (entity, key, meta) => {
      await entity.read('genLevelCtrl', [0x0202]);
    },
  },
  light_high_minimum_level: {
    key: ["light_high_minimum_level"],
    convertSet: async (entity, key, value, meta) => {
      await entity.write('genLevelCtrl', { 0x0203: { value, type: 0x20 } });
      return { state: { light_high_minimum_level: value }};
    },
    convertGet: async (entity, key, meta) => {
      await entity.read('genLevelCtrl', [0x0203]);
    },
  },
  light_high_maximum_level: {
    key: ["light_high_maximum_level"],
    convertSet: async (entity, key, value, meta) => {
      await entity.write('genLevelCtrl', { 0x0204: { value, type: 0x20 } });
      return { state: { light_high_maximum_level: value }};
    },
    convertGet: async (entity, key, meta) => {
      await entity.read('genLevelCtrl', [0x0204]);
    },
  },
  light_break_start: {
    key: ["light_break_start"],
    convertSet: async (entity, key, value, meta) => {
      await entity.write('genLevelCtrl', { 0x0205: { value, type: 0x20 } });
      return { state: { light_break_start: value }};
    },
    convertGet: async (entity, key, meta) => {
      await entity.read('genLevelCtrl', [0x0205]);
    },
  },
  light_break_end: {
    key: ["light_break_end"],
    convertSet: async (entity, key, value, meta) => {
      await entity.write('genLevelCtrl', { 0x0206: { value, type: 0x20 } });
      return { state: { light_break_end: value }};
    },
    convertGet: async (entity, key, meta) => {
      await entity.read('genLevelCtrl', [0x0206]);
    },
  },
};

const eLocal = {
  light_low_minimum_level: () => {
    return exposes
      .numeric("light_low_minimum_level", ea.GET | ea.SET)
      .withDescription("Low light minimum level")
  },
  light_low_maximum_level: () => {
    return exposes
      .numeric("light_low_maximum_level", ea.GET | ea.SET)
      .withDescription("Low light maximum level");
  },
  light_high_minimum_level: () => {
    return exposes
      .numeric("light_high_minimum_level", ea.GET | ea.SET)
      .withDescription("High light minimum level");
  },
  light_high_maximum_level: () => {
    return exposes
      .numeric("light_high_maximum_level", ea.GET | ea.SET)
      .withDescription("High light maximum level");
  },
  light_break_start: () => {
    return exposes
      .numeric("light_break_start", ea.GET | ea.SET)
      .withDescription("Dual light break start");
  },
  light_break_end: () => {
    return exposes
      .numeric("light_break_end", ea.GET | ea.SET)
      .withDescription("Dual light break end");
  },
};

const extendLocal = {
  light_onoff_brightness_colortemp: (options={}) => ({
    ...extend.light_onoff_brightness_colortemp(options),
    fromZigbee: [...extend.light_onoff_brightness_colortemp(options).fromZigbee, fz.command_on, fz.command_off, fz.command_move, fzLocal.light_configuration],
    toZigbee: [...extend.light_onoff_brightness_colortemp(options).toZigbee,
      tzLocal.light_low_minimum_level, tzLocal.light_low_maximum_level,
      tzLocal.light_high_minimum_level, tzLocal.light_high_maximum_level,
      tzLocal.light_break_start, tzLocal.light_break_end
    ],
    exposes: [...extend.light_onoff_brightness_colortemp(options).exposes,
      e.action(['on', 'off', 'brightness_move_up', 'brightness_move_down']),
      eLocal.light_low_minimum_level(), eLocal.light_low_maximum_level(),
      eLocal.light_high_minimum_level(), eLocal.light_high_maximum_level(),
      eLocal.light_break_start(), eLocal.light_break_end()]
  }),
};

const definition = {
  zigbeeModel: ["Table Lamp"],
  model: "Table Lamp",
  vendor: "Pieter",
  description: "Dimmable table lamp with light temperature",
  extend: extendLocal.light_onoff_brightness_colortemp({ colorTempRange: [153, 370] }),
  // The above numbers are 2700K to 6500K (in mireds).
};

module.exports = definition;
