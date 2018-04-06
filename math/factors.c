#include <stdio.h>

//#ifdef UNIT_TESTING
extern void mock_assert(const int result, const char* const expression, 
                        const char * const file, const int line);
#undef assert
#define assert(expression) \
    mock_assert((int)(expression), #expression, __FILE__, __LINE__);
//#endif // UNIT_TESTING

void factors(int x)
{
  assert(x > 0);
  int i;
  for(i = 1; i <= x; i++) {
    if(x % i == 0) {
      printf("%d ", i);
    }
  }
}
