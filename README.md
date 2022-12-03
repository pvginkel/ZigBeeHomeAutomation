# ZigBee Home Automation

This Arduino library allows you to easily build your own ZigBee lamps, switches and many other devices.

## How to create a device

This repository contains a few sample projects that show how to create a switch (the clock project),
a lamp, a sensor device. The `Clusters.h` file contains a large numbers of cluster types you can use as
a starting point. If they fit your need, implementing your device should be pretty straight forward. See
the sensors project for how to add your own custom attributes.

I connect to my devices using zigbee2mqtt and a flashed Sonoff Zigbee 3.0 USB Dongle Plus coordinator.
The sample projects contain device definition JavaScript files. These are based off of the instructions
on the zigbee2mqtt website at https://www.zigbee2mqtt.io/advanced/support-new-devices/01_support_new_devices.html.

## Acknowledgements

This library was heavily based on many other ZigBee libraries found on the Internet, but
especially on https://github.com/penner42/xbee-zha-arduino.

The clusters generated into the Clusters.h file uses a metadata definition in
[zigbee-herdsman](https://github.com/Koenkk/zigbee-herdsman/blob/master/src/zcl/definition/cluster.ts).
