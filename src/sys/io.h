#ifndef _IO_H
#define _IO_H 1
#include <stdint.h>

static inline void outb(uint8_t value, uint16_t port) {
  __asm__ __volatile__ ( 
      "outb %0, %1" 
      :
      :"a"(value), "Nd"(port)
      );
}

static inline uint8_t inb(uint16_t port) {
  uint8_t ret;
  __asm__ __volatile__ ( 
      "inb %1, %0"
      : "=a"(ret)
      : "Nd"(port)
      );
  return ret;
}
/*
static inline void outw(uint16_t value, uint16_t port) {
  __asm__ __volatile__ (
    "outw %0, %1"
    :
    : "a"(value), "Nd"(port)
    );
}

static inline uint16_t inw(uint16_t port) {
  uint16_t ret;
  __asm__ __volatile__ (
      "inw %1, %0"
      : "=a"(ret)
      : "Nd"(port)
      );
  return ret;
}

static inline void outl(uint32_t value, uint16_t port) {
  __asm__ __volatile__ (
      "outl %0, %1"
      :
      : "a"(value), "Nd"(port)
      );
}

static inline uint32_t inl(uint32_t value, uint16_t port) {
  uint32_t ret;
  __asm__ __volatile__ (
      "inl %1, %0"
      : "=a"(ret)
      : "Nd"(port)
      );
  return ret;
}
*/
#endif //_KIO_H
