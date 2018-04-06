#include <assert.h>

//#ifdef UNIT_TESTING
extern void mock_assert(const int result, const char* const expression,
                        const char * const file, const int line);
#undef assert
#define assert(expression) \
    mock_assert(((expression) ? 1 : 0), #expression, __FILE__, __LINE__);
//#endif /* UNIT_TESTING */

long int factorial(int x)
{
  long int f = 1;
  int i;
  for(i = 2; i <= x; i++){
    f = f * i;
  }
  return f;
}

long int nCr(int n, int r)
{
  assert(n >= 0 && r >= 0 && n >= r);
  long int a = factorial(n) / (factorial(r) * factorial(n - r));
  return a;
}
