#ifndef _KIO_H
#define _KIO_H
#include <stddef.h>
#include <stdint.h>

static inline void koutb(uint8_t value, uint16_t port) {
  __asm__ __volatile__ ( 
      "outb %0, %1" 
      :
      :"a"(value), "Nd"(port)
      );
}

static inline uint8_t kinb(uint16_t port) {
  uint8_t ret;
  __asm__ __volatile__ ( 
      "inb %1, %0"
      : "=a"(ret)
      : "Nd"(port)
      );
  return ret;
}

#endif //_KIO_H
