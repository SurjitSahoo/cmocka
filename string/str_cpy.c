#include <assert.h>
#include <stdlib.h>

//#ifdef UNIT_TESTING
extern void mock_assert(const int result, const char* const expression,
                        const char * const file, const int line);
#undef assert
#define assert(expression) \
    mock_assert(((expression) ? 1 : 0), #expression, __FILE__, __LINE__);
//#endif /* UNIT_TESTING */

/** Copies a string and returns the address of it **/
char *strcopy(char *str)
{
  assert(str != NULL);
  int i;
  char *copy =(char *)malloc(100*sizeof(char));
  for(i = 0; str[i] != '\0'; ++i)
    copy[i] = str[i];
  copy[i] = '\0';
  return copy;
}
