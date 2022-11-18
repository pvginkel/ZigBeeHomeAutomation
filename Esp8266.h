#ifdef ESP8266

#include <ESP8266WiFi.h>

#define esp8266_yield() yield()

#else

#define esp8266_yield()

#endif
