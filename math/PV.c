#include <assert.h>

//#ifdef UNIT_TESTING
extern void mock_assert(const int result, const char* const expression,
                        const char * const file, const int line);
#undef assert
#define assert(expression) \
    mock_assert(((expression) ? 1 : 0), #expression, __FILE__, __LINE__);
//#endif /* UNIT_TESTING */

double PV(double rate, unsigned int nperiods, double FV)
{
  assert(rate >= 0 && nperiods >= 0 && FV >= 0);
  int i;
  double value = (1 + rate);
  double x = 1, result;
  for(i = 0; i < nperiods; i++){
    x *= value;
  }
  result = FV / x;
  return result;
}
