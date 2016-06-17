#include <string.h>
#include <stddef.h>

//TODO: Sanitize this with paging in case our string overruns.
size_t strlen(const char* str) {
  size_t ret = 0;
  while( str[ret] != 0 ) {
    ret++;
  }
  return ret;
}
