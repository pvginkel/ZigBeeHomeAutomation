/* 
	Editor: https://www.visualmicro.com/
			This file is for intellisense purpose only.
			Visual micro (and the arduino ide) ignore this code during compilation. This code is automatically maintained by visualmicro, manual changes to this file will be overwritten
			The contents of the _vm sub folder can be deleted prior to publishing a project
			All non-arduino files created by visual micro and all visual studio project or solution files can be freely deleted and are not required to compile a sketch (do not delete your own code!).
			Note: debugger breakpoints are stored in '.sln' or '.asln' files, knowledge of last uploaded breakpoints is stored in the upload.vmps.xml file. Both files are required to continue a previous debug session without needing to compile and upload again
	
	Hardware: Arduino Nano Every                                                                                                                             (nona4809), Platform=megaavr, Package=arduino
*/

#if defined(_VMICRO_INTELLISENSE)

#ifndef _VSARDUINO_H_
#define _VSARDUINO_H_
#define __AVR_atmega4809__ 1
#define __MEGAAVR_ATmega4809__ 1
#define __AVR_ATmega4809__ 1
#define _VMDEBUG 1
#define F_CPU 16000000L
#define ARDUINO 108010
#define ARDUINO_AVR_NANO_EVERY 1
#define ARDUINO_ARCH_MEGAAVR 1
#define AVR_NANO_4809_328MODE 1
#define MILLIS_USE_TIMERB3 1
#define NO_EXTERNAL_I2C_PULLUP 1
#define __cplusplus 201103L
#define _Pragma(x)
#define __AVR__
#define __inline__
#define __asm__(...)
#define __extension__
#define __inline__
#define __volatile__
// Redefine __cplusplus to correct version: https://www.visualmicro.com/forums/YaBB.pl?num=1592217268
#undef __cplusplus
#define __cplusplus 201103L

//#define GCC_VERSION 40902
//https://www.visualmicro.com/forums/YaBB.pl?num=1569762585/5#5
#define __GNUC__             5
#define __GNUC_MINOR__       4
#define __GNUC_PATCHLEVEL__  0
#define GCC_VERSION ((__GNUC__*10000)+(__GNUC_MINOR__*100)+__GNUC_PATCHLEVEL__)) 


#define volatile(va_arg) 
#define _CONST
#define __builtin_va_start
#define __builtin_va_end
#define __attribute__(...)
#define NOINLINE __attribute__((noinline))
#define prog_void
#define PGM_VOID_P int


#ifndef __builtin_constant_p
	#define __builtin_constant_p __attribute__((__const__))
#endif
#ifndef __builtin_strlen
	#define __builtin_strlen  __attribute__((__const__))
#endif


#define NEW_H
typedef void *__builtin_va_list;
//extern "C" void __cxa_pure_virtual() {;}

typedef int div_t;
typedef int ldiv_t;


typedef void *__builtin_va_list;
//extern "C" void __cxa_pure_virtual() {;}



#include <arduino.h>
#include <pins_arduino.h> 
#include <timers.h> 
//#undef F
//#define F(string_literal) ((const PROGMEM char *)(string_literal))
#undef PSTR
#define PSTR(string_literal) ((const PROGMEM char *)(string_literal))

//typedef unsigned char uint8_t;
//typedef unsigned int uint8_t;

#define pgm_read_byte_near(address_short) uint8_t()
#define pgm_read_byte(address_short) uint8_t() 
#define pgm_read_word(address_short) uint16_t() 
#define pgm_read_dword(address_short) uint32_t()
#define pgm_read_float(address_short) float()
#define pgm_read_ptr(address_short)   short()

// Additions from toolchain\avr\include\string.h
extern int ffs(int __val) __ATTR_CONST__;
extern int ffs(int __val) __ATTR_CONST__ { }
extern int ffsl(long __val) __ATTR_CONST__;
extern int ffsl(long __val) __ATTR_CONST__ { }
__extension__ extern int ffsll(long long __val) __ATTR_CONST__;
__extension__ extern int ffsll(long long __val) __ATTR_CONST__ { }
extern void* memccpy(void*, const void*, int, size_t);
extern void* memccpy(void*, const void*, int, size_t) { }
extern void* memchr(const void*, int, size_t) __ATTR_PURE__;
extern void* memchr(const void*, int, size_t) __ATTR_PURE__ { }
extern int memcmp(const void*, const void*, size_t) __ATTR_PURE__;
extern int memcmp(const void*, const void*, size_t) __ATTR_PURE__ { }
extern void* memcpy(void*, const void*, size_t);
extern void* memcpy(void*, const void*, size_t) { }
extern void* memmem(const void*, size_t, const void*, size_t) __ATTR_PURE__;
extern void* memmem(const void*, size_t, const void*, size_t) __ATTR_PURE__ { }
extern void* memmove(void*, const void*, size_t);
extern void* memmove(void*, const void*, size_t) { }
extern void* memrchr(const void*, int, size_t) __ATTR_PURE__;
extern void* memrchr(const void*, int, size_t) __ATTR_PURE__ { }
extern void* memset(void*, int, size_t);
extern void* memset(void*, int, size_t) { }
extern char* strcat(char*, const char*);
extern char* strcat(char*, const char*) { }
extern char* strchr(const char*, int) __ATTR_PURE__;
extern char* strchr(const char*, int) __ATTR_PURE__ { }
extern char* strchrnul(const char*, int) __ATTR_PURE__;
extern char* strchrnul(const char*, int) __ATTR_PURE__ { }
extern int strcmp(const char*, const char*) __ATTR_PURE__;
extern int strcmp(const char*, const char*) __ATTR_PURE__ { }
extern char* strcpy(char*, const char*);
extern char* strcpy(char*, const char*) { }
extern int strcasecmp(const char*, const char*) __ATTR_PURE__;
extern int strcasecmp(const char*, const char*) __ATTR_PURE__ { }
extern char* strcasestr(const char*, const char*) __ATTR_PURE__;
extern char* strcasestr(const char*, const char*) __ATTR_PURE__ { }
extern size_t strcspn(const char* __s, const char* __reject) __ATTR_PURE__;
extern size_t strcspn(const char* __s, const char* __reject) __ATTR_PURE__ { }
extern char* strdup(const char* s1);
extern char* strdup(const char* s1) { }
extern size_t strlcat(char*, const char*, size_t);
extern size_t strlcat(char*, const char*, size_t) { }
extern size_t strlcpy(char*, const char*, size_t);
extern size_t strlcpy(char*, const char*, size_t) { }
extern size_t strlen(const char*) __ATTR_PURE__;
extern size_t strlen(const char*) __ATTR_PURE__ { }
extern char* strlwr(char*);
extern char* strlwr(char*) { }
extern char* strncat(char*, const char*, size_t);
extern char* strncat(char*, const char*, size_t) { }
extern int strncmp(const char*, const char*, size_t) __ATTR_PURE__;
extern int strncmp(const char*, const char*, size_t) __ATTR_PURE__ { }
extern char* strncpy(char*, const char*, size_t);
extern char* strncpy(char*, const char*, size_t) { }
extern int strncasecmp(const char*, const char*, size_t) __ATTR_PURE__;
extern int strncasecmp(const char*, const char*, size_t) __ATTR_PURE__ { }
extern size_t strnlen(const char*, size_t) __ATTR_PURE__;
extern size_t strnlen(const char*, size_t) __ATTR_PURE__ { }
extern char* strpbrk(const char* __s, const char* __accept) __ATTR_PURE__;
extern char* strpbrk(const char* __s, const char* __accept) __ATTR_PURE__ { }
extern char* strrchr(const char*, int) __ATTR_PURE__;
extern char* strrchr(const char*, int) __ATTR_PURE__ { }
extern char* strrev(char*);
extern char* strrev(char*) { }
extern char* strsep(char**, const char*);
extern char* strsep(char**, const char*) { }
extern size_t strspn(const char* __s, const char* __accept) __ATTR_PURE__;
extern size_t strspn(const char* __s, const char* __accept) __ATTR_PURE__ { }
extern char* strstr(const char*, const char*) __ATTR_PURE__;
extern char* strstr(const char*, const char*) __ATTR_PURE__ { }
extern char* strtok(char*, const char*);
extern char* strtok(char*, const char*) { }
extern char* strtok_r(char*, const char*, char**);
extern char* strtok_r(char*, const char*, char**) { }
extern char* strupr(char*);
extern char* strupr(char*) { }

#include "xbee.ino"
#endif
#endif
