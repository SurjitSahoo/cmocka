#include <stdlib.h>
#include <assert.h>
void *mem_copy(void *dest, const void *src, unsigned int n)
{
  assert(src != NULL);  
  int i;
  char* newsrc = (char*)src;
  char* newdest = (char*)dest;
  if(newdest < newsrc)
    for(i = 0; i < n; i++)
      newdest[i] = newsrc[i];
  else{
    /* Copy backwards so that memory won't overlap */
    for(i = (n - 1); i >= 0; i--)
      newdest[i] = newsrc[i];
  }
  return dest;  
}
