#include <assert.h>
#include <stdlib.h>

//#ifdef UNIT_TESTING
extern void mock_assert(const int result, const char* const expression,
                        const char * const file, const int line);
#undef assert
#define assert(expression) \
    mock_assert(((expression) ? 1 : 0), #expression, __FILE__, __LINE__);
//#endif /* UNIT_TESTING */

char **str_split(char *str, char c)
{
  assert(str != NULL);
  char **tokens = NULL;
  int count = 0;
  while(*str){
    while(*str == c)
      ++str;
    if(!*str)
      break;
    tokens = realloc(tokens, (count+1) * sizeof(*tokens));
      tokens[count++] = str;
    while(*str && *str != c)
      ++str;
    if(*str)
      *str++ = 0;
  }
  tokens = realloc(tokens, (count+1) * sizeof(*tokens));
  tokens[count] = NULL;
  return tokens;
}
