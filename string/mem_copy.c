#include <stdlib.h>
#include <assert.h>

//#ifdef UNIT_TESTING
extern void mock_assert(const int result, const char* const expression,
                        const char * const file, const int line);
#undef assert
#define assert(expression) \
    mock_assert(((expression) ? 1 : 0), #expression, __FILE__, __LINE__);
//#endif /* UNIT_TESTING */

void *mem_copy(void *dest, const void *src, unsigned int n)
{
  assert(src != NULL && dest != NULL);  
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

