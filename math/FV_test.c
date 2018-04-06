#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

extern double FV(double rate, unsigned int nperiods, double PV);

void all_zero(void **state)
{
  assert_int_equal(FV(0,0,0), 0);
}

void rate_zero(void **state)
{
  assert_int_equal(FV(0, 2, 1000), 1000);
}

void nperiods_zero(void **state)
{
  assert_int_equal(FV(5, 0, 1000), 1000);
}

void PV_zero(void **state)
{
  assert_int_equal(FV(5, 2, 0), 0);
}

void all_negative(void **state)
{
  expect_assert_failure(FV(-5, -2, -1000));
}

void rate_negative(void **state)
{
  expect_assert_failure(FV(-5, 2, 1000));
}

void nperiods_negative(void **state)
{
  expect_assert_failure(FV(5, -2, 1000));
}

void PV_negative(void **state)
{
  expect_assert_failure(FV(5, 2, -1000));
}

void all_positive(void **state)
{
  assert_int_equal(FV(5, 2, 100), 3600);
}

int main(int argc, char *argv[])
{
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(all_zero),
    cmocka_unit_test(rate_zero),
    cmocka_unit_test(nperiods_zero),
    cmocka_unit_test(PV_zero),
    cmocka_unit_test(all_negative),
    cmocka_unit_test(rate_negative),
    cmocka_unit_test(nperiods_negative),
    cmocka_unit_test(PV_negative),
    cmocka_unit_test(all_positive),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}
