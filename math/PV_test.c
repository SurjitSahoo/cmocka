#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

extern double PV(double rate, unsigned int nperiods, double FV);

void all_zero(void **state)
{
  assert_int_equal(PV(0,0,0), 0);
}

void rate_zero(void **state)
{
  assert_int_equal(PV(0, 2, 1000), 1000);
}

void nperiods_zero(void **state)
{
  assert_int_equal(PV(5, 0, 1000), 1000);
}

void FV_zero(void **state)
{
  assert_int_equal(PV(5, 2, 0), 0);
}

void all_negative(void **state)
{
  expect_assert_failure(PV(-5, -2, -1000));
}

void rate_negative(void **state)
{
  expect_assert_failure(PV(-5, 2, 1000));
}

void nperiods_negative(void **state)
{
  expect_assert_failure(PV(5, -2, 1000));
}

void FV_negative(void **state)
{
  expect_assert_failure(PV(5, 2, -1000));
}

void all_positive(void **state)
{
  assert_int_equal(PV(5, 2, 1000), 27);
}

int main(int argc, char* argv[])
{
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(all_zero),
    cmocka_unit_test(rate_zero),
    cmocka_unit_test(nperiods_zero),
    cmocka_unit_test(FV_zero),
    cmocka_unit_test(all_negative),
    cmocka_unit_test(rate_negative),
    cmocka_unit_test(nperiods_negative),
    cmocka_unit_test(FV_negative),
    cmocka_unit_test(all_positive),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}
