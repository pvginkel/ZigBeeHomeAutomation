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

## Important notes

API mode needs to be 2 for XBee. This is now auto configured by the library.

Shut down any other coordinators in the house before you start testing your own implementation.

The XBee device needs to be configured as an end device in API mode. You can't switch from the
AT mode to API mode. See https://alselectro.wordpress.com/2017/01/23/zigbee-xbee-s2c-how-to-configure-as-coordinator-router-end-device/
for how to use an Arduino to upload firmware.

The XBee device won't be listening to all channels by default.

See https://www.youtube.com/watch?v=MdFFZGco3jg for instructions on how
to recover an unresponsive modem. Basically the instructions are:

* Set the boud rate to 115200.
* Remove the modem from the USB adapter.
* Select the device type, firmware type and version, and reset all settings
  to their default value.
* Click Write.
* When the prompt appears to reset the modem, hold down the reset button
  while you insert the modem.

The firmware write process should now complete successfully.
