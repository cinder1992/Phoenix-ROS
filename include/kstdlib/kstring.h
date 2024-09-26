#ifndef _KSTDLIB_STRING_H
#define _KSTDLIB_STRING_H
#include <stddef.h>

void *memcpy(void *, const void *, size_t);
void *memset(void *, int, size_t);
void *memmove(void *, const void *, size_t);
int memcmp(const void *, const void *, size_t);
size_t strlen(const char*);

#endif
