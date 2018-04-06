#include <stdio.h>
#include <assert.h>

//#ifdef UNIT_TESTING
extern void mock_assert(const int result, const char* const expression,
                        const char * const file, const int line);
#undef assert
#define assert(expression) \
    mock_assert(((expression) ? 1 : 0), #expression, __FILE__, __LINE__);
//#endif /* UNIT_TESTING */

void primefactor(unsigned int x)
{
  assert(x > 0);
  int i, j, c = 0;
  for(i = 1; i <= x; i++) {
    c = 0;
    if((x % i) == 0) {
      for( j= 1; j <= i; j++) {
        if((i % j) == 0)
          c++;
      }
        if(c == 2)
          printf(" %d ", i);
    }
  }
}
