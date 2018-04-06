#include <stdlib.h>
#include <assert.h>

//#ifdef UNIT_TESTING
extern void mock_assert(const int result, const char* const expression,
                        const char * const file, const int line);
#undef assert
#define assert(expression) \
    mock_assert(((expression) ? 1 : 0), #expression, __FILE__, __LINE__);
//#endif /* UNIT_TESTING */

int str_copy(char *str1, char *str2)
{
  assert((str1 != NULL) && (str2 != NULL));
  int i;
  for(i = 0; str2[i] != '\0'; ++i) {
    str1[i] = str2[i];
  }
  str1[i] = '\0';
  if ((str1[i] == '\0') && (str2[i] == '\0'))
    return 0;
  else
    return -1;
}
