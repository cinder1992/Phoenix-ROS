#ifndef _VGA_H
#define _VGA_H

#include <stddef.h>
#include <stdint.h>
#define VGA_HEIGHT 25
#define VGA_WIDTH 80
#define VGA_COLORWORD(f,b) (f | b << 4)
#define VGA_ENTRY(ch,cl) ((uint16_t) (ch | cl << 8))

//TODO: Seperate VGA and TERM into two seperate entities

enum vga_colors {
  COLOR_BLACK = 0,
  COLOR_BLUE = 1,
  COLOR_GREEN = 2,
  COLOR_CYAN = 3,
  COLOR_RED = 4,
  COLOR_MAGENTA = 5,
  COLOR_BROWN = 6,
  COLOR_LIGHT_GREY = 7,
  COLOR_DARK_GREY = 8,
  COLOR_LIGHT_BLUE = 9,
  COLOR_LIGHT_GREEN = 10,
  COLOR_LIGHT_CYAN = 11,
  COLOR_LIGHT_RED = 12,
  COLOR_LIGHT_MAGENTA = 13,
  COLOR_LIGHT_BROWN = 14,
  COLOR_WHITE = 15,
};

size_t term_x;
size_t term_y;
uint8_t term_color;
uint16_t* term_buffer;

void term_init();
void term_setcolor(uint8_t);
void vga_putat(char, uint8_t, size_t, size_t);
void term_putchar(char);
void term_putstr(const char*);

#endif

