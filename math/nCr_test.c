#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

extern long int nCr(int n, int r);

//n zero allowed but, n < r not allowed
void n_zero(void **state)
{
  expect_assert_failure(nCr(0, 3));
}

void r_zero(void **state)
{
  assert_int_equal(nCr(3, 0), 1);
}

void both_zero(void **sate)
{
  assert_int_equal(nCr(0, 0), 1);
}

void both_negative(void **state)
{
  expect_assert_failure(nCr(-3, -2));
}

void n_negative(void **state)
{
  expect_assert_failure(nCr(-3, 2));
}

void r_negative(void **state)
{
  expect_assert_failure(nCr(3, -2));
}

void both_positive_nlesr(void **state)
{
  expect_assert_failure(nCr(2, 3));
}

void both_positive_ngreaterr(void **state)
{
  assert_int_equal(nCr(3, 2), 3);
}

int main(int argc, char *argv[])
{
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(n_zero),
    cmocka_unit_test(r_zero),
    cmocka_unit_test(both_zero),
    cmocka_unit_test(both_negative),
    cmocka_unit_test(n_negative),
    cmocka_unit_test(r_negative),
    cmocka_unit_test(both_positive_nlesr),
    cmocka_unit_test(both_positive_ngreaterr),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}

