#include <kserial.h>
#include <kio.h>
#include <stddef.h>
#include <stdint.h>
#define COM1 0x3F8

void init_serial() {
  koutb(0x00, COM1 + 1); //Disable serial interrupts
  koutb(0x80, COM1 + 3); //Enable DLAB
  koutb(0x03, COM1 + 0); //Set Baudrate divisor to 3 (lowbyte)
  koutb(0x00, COM1 + 1); //Baudrate devisor highbyte
  koutb(0x03, COM1 + 3); //8 bits, no parity, 1 stop bit.
  koutb(0xC7, COM1 + 2); //enable FIFO buffer, clear buffer, 14 byte threashold
  koutb(0x0B, COM1 + 4); //enable IRQs... but don't actually send any.
}

char serial_getchar() { 
  while((kinb(COM1 + 5) & 1) == 0); //TODO: Make this interrupt driven instead of blocking

  return(kinb(COM1));
}

void serial_putchar(char chr) {
  while((kinb(COM1 + 5) & 0x20) == 0); //"Dirty" blocking so that we don't overfill the buffer

  koutb(chr, COM1);
}

