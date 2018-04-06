#include <stdio.h>
#include <assert.h>

//#ifdef UNIT_TESTING
extern void mock_assert(const int result, const char* const expression, 
                        const char * const file, const int line);
#undef assert
#define assert(expression) \
    mock_assert((int)(expression), #expression, __FILE__, __LINE__);
//#endif // UNIT_TESTING

void fibonacci(int n)
{
  assert(n >= 0);
  int i, t1 = 0, t2 = 1, t3 = 0;
  printf("Fibonacci Series: ");
  printf("\n %d", t1);
  printf("\n %d", t2);
  for(i = 1; i <= (n - 2); ++i){
    t3 = t1 + t2;
    t1 = t2;
    t2 = t3;
    printf("\n %d", t3);
  }
}

