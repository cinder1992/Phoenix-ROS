#include <stddef.h>
#include <stdint.h>
#include <vga.h>
#include <kstring.h> //TODO: Replace with libc string.h
#include <kserial.h>

void term_init() {
  init_serial(); //TODO: Standardise all _init names
  term_x = 0;
  term_y = 0;
  term_color = VGA_COLORWORD(COLOR_LIGHT_GREY, COLOR_BLACK);
  term_buffer = (uint16_t*) 0xB8000; //I don't like magic numbers but VGA does.

  for( size_t y = 0; y < VGA_HEIGHT; y++ ) {
    for( size_t x = 0; x < VGA_WIDTH; x++ ) {
      const size_t index = y * VGA_WIDTH + x; 
      term_buffer[index] = VGA_ENTRY(' ', term_color);
    }
  }
}

void term_setcolor(uint8_t color) {
  term_color = color;
}

void vga_putat(char c, uint8_t color, size_t x, size_t y) {
  const size_t index = y * VGA_WIDTH + x;
  term_buffer[index] = VGA_ENTRY(c, color);
}

void term_putchar(char c) { //TODO: Move terminal functions to their own file.
  serial_putchar(c); //Push the character onto the serial buffer in case of horrible VGA corruption!
  switch(c) {
    case '\n': //Line feed '\n'
      term_y++;
    case '\r': //Carrage Return
      term_x = -1; //simplify via overflow to produce the correct alignment
      break;
    default:
      vga_putat(c, term_color, term_x, term_y);
  }
  if( ++term_x == VGA_WIDTH ) {
    term_x = 0;
    if( ++term_y == VGA_HEIGHT ) {
      term_y = 0;
    }
  }
}

void term_putstr(const char* str) {
  size_t len = strlen(str);
  for( size_t i = 0; i < len; i++ )
    term_putchar(str[i]);
}

