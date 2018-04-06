#include <assert.h>
#include <stdlib.h>

//#ifdef UNIT_TESTING
extern void mock_assert(const int result, const char* const expression,
                        const char * const file, const int line);
#undef assert
#define assert(expression) \
    mock_assert(((expression) ? 1 : 0), #expression, __FILE__, __LINE__);
//#endif /* UNIT_TESTING */

int str_compare(char *a, char *b)
{
    assert(a != NULL && b != NULL);
    while (*a && *b && *a == *b) { 
      ++a; 
      ++b; 
    }
    return *a - *b;
}
