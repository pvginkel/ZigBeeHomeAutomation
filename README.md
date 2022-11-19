# XBee

Work in progress!

## Important notes

API mode needs to be 2 for XBee. This is now auto configured by the library.

Shut down any other coordinators in the house before you start testing your own implementation.

The XBee device needs to be configured as an end device in API mode. You can't switch from the AT mode to API mode. See https://alselectro.wordpress.com/2017/01/23/zigbee-xbee-s2c-how-to-configure-as-coordinator-router-end-device/ for how to use an Arduino to upload firmware.

The XBee device won't be listening to all channels by default.
