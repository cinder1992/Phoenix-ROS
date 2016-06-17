#ifndef _STDIO_H
#define _STDIO_H 1

#ifndef NULL
#define NULL 0
#endif //NULL

#include <stdarg.h>
#include <stddef.h>

//TODO: Make the FILE structure opaque.
//Define our pointer types for write
typedef int (*_WRITE_PTR)(int);
typedef int (*_READ_PTR)();

typedef struct _IO_FILE {
  size_t _FILE_DESC;
  size_t* _IO_FILE_BUF;
  size_t* _IO_FILE_BUF_END;
  _WRITE_PTR _WRITE;
  _READ_PTR _READ;
} FILE;

/*
 * TODO: initialise the IO properly somehow...
typedef _IO_FILE stdout;
typedef _IO_FILE stdin;

#define stdout stdout
#define stdin stdin
*/
//int printf(const char *, ...);
int fprintf(FILE*, const char *, ...);
int vfprintf(FILE*, const char *, va_list);
int fputc(int, FILE*);
int fputs(const char *, FILE*);
int getc(FILE*);


#endif //_STDIO_H
