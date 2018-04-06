#include <assert.h>

//#ifdef UNIT_TESTING
extern void mock_assert(const int result, const char* const expression, 
                        const char * const file, const int line);
#undef assert
#define assert(expression) \
    mock_assert((int)(expression), #expression, __FILE__, __LINE__);
//#endif // UNIT_TESTING

double FV(double rate, unsigned int nperiods, double PV)
{
  assert((rate >= 0) && (nperiods >= 0) && (PV >= 0));
  int i;
  double value = (1 + rate) ;
  double x = 1, result;
  for(i = 0; i < nperiods; i++){
    x *= value;
  }
  result = PV * x;
  return result;
}

