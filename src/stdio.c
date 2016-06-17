#include <stddef.h>
#include <stdio.h>
#include <stdarg.h>
//#include <stdlib.h>
#include <string.h>

FILE * debug;

char* _pad(char*, int, char); //forward declaring internal functions
char* _itoa(int, char*, int);
char* _reverse(char*, int);

int fprintf(FILE* f, const char* format, ...) {
  va_list args;
  int retval;
  va_start(args, format);
  retval = vfprintf(f, format, args);
  va_end(args);

  return retval;
}

int vfprintf(FILE* f, const char* format, va_list args) { //TODO: support the length modifier!
  char buf[20];
  char chr;
  int tempArg;
  debug = f;
  while((chr = *format++) != 0) {
    if (chr != '%')
      fputc(chr, f);   //All we have is a normal character, print it.
    else {
      int pad0, padN;
      chr = *format++;  //increment char
      if(chr == '0') { //are we padding zeros?
        pad0 = 1;
        chr = *format++;
      }
      if(chr >= '0' && chr <= '9') { //How many digets to pad?
        padN = chr - '0';
        chr = *format++;
      } else
        padN = 0;
      switch(chr) {
        case 'd':
        case 'i':
        case 'u':
          tempArg = va_arg(args, int);
          _itoa(tempArg, buf, 10);
          fputs(_pad(buf, padN, pad0 ? '0':' '), f);
          //fputs(buf, f);
          break;

        case 'x':
          tempArg = va_arg(args, int);
          _itoa(tempArg, buf, 16);
          fputs(_pad(buf, padN, pad0 ? '0':' '), f);
          //fputs(buf, f);
          break;

        case 's':
          tempArg = va_arg(args, int);
          fputs((char*) tempArg, f); //Might not work!
          break;
        default:
          fputc(chr, f);
          break;
      }
    }
  }
  return 0;
}

int fputc(int c, FILE* f) {
  int retval;
  retval = f->_WRITE(c);
  return retval;
}

int fputs(const char* s, FILE* f) {
  while(*s) {
    fputc(*s++, f);
  }
  return 0; //TODO: Return error code on error.
}

int getc(FILE* f) {
  int retval;
  retval = f->_READ();
  return retval;
}

//Begin internal functions
char* _pad(char* buffer, int maxPadN, char padChar) {
  int padN = maxPadN - strlen(buffer);
  if(padN > 0) {
    for(int i = strlen(buffer); i >= 0; i--) { //ghetto strcopy
      buffer[i+padN] = buffer[i];
    }
    for(int i = 0; i < padN; i++) {
      buffer[i] = padChar;
    }
  }
  return buffer;
}

char* _itoa(int v, char* s, int radix) { //May not work!
  int i = 0;
  int isNeg;
  unsigned int vU;

  if(v == 0) { //handle zero
    s[i++] = '0';
    s[i] = '\0';
    return s;
  }

  if(v < 0 && radix == 10) {
    isNeg = 1;
    v = -v;
  }
  else {
    isNeg = 0;
  }
  
  if (radix == 10) {
    while(v) {
      int rem = v % radix;
      s[i++] = (rem > 9) ? (rem - 10) + 'A' : rem + '0';
      v = v / radix;
    }
    if(isNeg == 1)
      s[i++] = '-'; //double termination, doesn't matter for this.
  } else {
    vU = (unsigned)v; 
    while(vU) {
      unsigned int rem = vU % radix;
      s[i++] = (rem > 9) ? (rem - 10) + 'A' : rem + '0';
      vU = vU / radix;
    }
  }
  
  s[i] = '\0'; //null-terminate it!
  _reverse(s, i);

  return s;
}

char* _reverse(char* s, int len) {
  int start = 0;
  int end = len - 1;
  char temp;
  while(start < end) {
    temp = s[start];
    s[start] = s[end];
    s[end] = temp;
    start++;
    end--;
  }
  return s;
}
