#include "serial.h"
#include "../../sys/io.h"
#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#define COM1 0x3F8

void init_serial() {
  outb(0x00, COM1 + 1); //Disable serial interrupts
  outb(0x80, COM1 + 3); //Enable DLAB
  outb(0x03, COM1 + 0); //Set Baudrate divisor to 3 (lowbyte)
  outb(0x00, COM1 + 1); //Baudrate devisor highbyte
  outb(0x03, COM1 + 3); //8 bits, no parity, 1 stop bit.
  outb(0xC7, COM1 + 2); //enable FIFO buffer, clear buffer, 14 byte threashold
  outb(0x0B, COM1 + 4); //enable IRQs... but don't actually send any.
}

int serial_read() { 
  while((inb(COM1 + 5) & 1) == 0); //TODO: Make this interrupt driven instead of blocking

  return((int)inb(COM1));
}

int serial_write(int chr) {
  while((inb(COM1 + 5) & 0x20) == 0); //"Dirty" blocking so that we don't overfill the buffer

  outb(chr, COM1);
  return 0; //TODO: Error checking on the serial bus.
}

FILE* fopen_serial(FILE* fptr) {
  init_serial();
  fptr->_WRITE = &serial_write;
  fptr->_READ = &serial_read;
  fptr->_FILE_DESC = 4; //TODO: NO MAGIC NUMBERS!
  return fptr;
}

