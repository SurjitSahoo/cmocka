#include <assert.h>

//#ifdef UNIT_TESTING
extern void mock_assert(const int result, const char* const expression, 
                        const char * const file, const int line);
#undef assert
#define assert(expression) \
    mock_assert((int)(expression), #expression, __FILE__, __LINE__);
//#endif // UNIT_TESTING

int is_prime(unsigned int x)
{
  assert(x > 0);
  int i, c = 0, y = x  / 2;
  for(i = 2; i <= y; i++){
    if((x % i) == 0)
      c++;
  }
  if(c == 0)
    return 1;
  else
    return 0;
}
