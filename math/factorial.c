#include <assert.h>

//#ifdef UNIT_TESTING
extern void mock_assert(const int result, const char* const expression, 
                        const char * const file, const int line);
#undef assert
#define assert(expression) \
    mock_assert((int)(expression), #expression, __FILE__, __LINE__);
//#endif // UNIT_TESTING

long int factorial(int x)
{
  assert(x >= 0);
  long int f = 1;
  int i;
  for(i = 2; i <= x; i++){
    f = f * i;
  }
  return f;
}
