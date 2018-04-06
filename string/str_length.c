#include <assert.h>
#include <stdlib.h>

//#ifdef UNIT_TESTING
extern void mock_assert(const int result, const char* const expression,
                        const char * const file, const int line);
#undef assert
#define assert(expression) \
    mock_assert(((expression) ? 1 : 0), #expression, __FILE__, __LINE__);
//#endif /* UNIT_TESTING */

int str_length(char *str)
{
  assert(str != NULL);
  int count = 0;
  while(*str != '\0') {
    count += 1;
    str++;
  }
  if(count > 0)
    return count;
  else
    return -1;
}
