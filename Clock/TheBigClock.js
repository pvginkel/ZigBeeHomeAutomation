const fz = require("zigbee-herdsman-converters/converters/fromZigbee");
const tz = require("zigbee-herdsman-converters/converters/toZigbee");
const exposes = require("zigbee-herdsman-converters/lib/exposes");
const reporting = require("zigbee-herdsman-converters/lib/reporting");
const extend = require("zigbee-herdsman-converters/lib/extend");
const e = exposes.presets;
const ea = exposes.access;
const herdsman = require("zigbee-herdsman");
const DataType = herdsman.Zcl.DataType;
const { Buffer } = require("buffer");

/*
const tzLocal = {
  currentDateTime: {
    key: ["currentDateTime"],
    convertSet: async (entity, key, value, meta) => {
      await entity.write("genBasic", { 0x0201: { value, type: 76 } });
      return { state: { [key]: value } };
    },
    convertGet: async (entity, key, meta) => {
      await entity.read("genBasic", [0x0201]);
    },
  },
};
*/
const definition = {
  zigbeeModel: ["The Big Clock"],
  model: "The Big Clock",
  vendor: "Pieter",
  description: "The Big Clock",
  extend: extend.light_onoff_brightness(),
  onEvent: async (type, data, device, options, state) => {
    // Tell the clock the current date/time as we know it.

    if (type === "deviceAnnounce") {
      const endpoint = device.getEndpoint(1);
      const date = new Date();

      // The default response isn't being picked up.
      const options = { disableDefaultResponse: true };

      const payload = {
        0x0201: {
          value:
            ((date.getFullYear() - 1900) << 24) |
            ((date.getMonth() + 1) << 16) |
            (date.getDate() << 8) |
            date.getDay(), // Day of the week
          type: DataType.uint32,
        },
        0x0202: {
          value:
            (date.getHours() << 24) |
            (date.getMinutes() << 16) |
            (date.getSeconds() << 8) |
            ((date.getMilliseconds() / 10) | 0),
          type: DataType.uint32,
        },
      };

      await endpoint.write("genBasic", payload, options);
    }
  },
};

module.exports = definition;
