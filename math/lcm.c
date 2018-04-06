#include <stdio.h>
#include <assert.h>
#include <stdio.h>

//#ifdef UNIT_TESTING
extern void mock_assert(const int result, const char* const expression, 
                        const char * const file, const int line);
#undef assert
#define assert(expression) \
    mock_assert((int)(expression), #expression, __FILE__, __LINE__);
//#endif // UNIT_TESTING

int lcm(int a, int b, int c)
{
  assert(a > 0 && b > 0 && c > 0);
  int i = 1, x, l;
  x = a * b * c;
  while(c <= x){
    if((i % a) == 0 && (i % b) == 0 && (i % c) == 0){
      l = i;
      break;
    }
    i++;
  }
  return l;
}

