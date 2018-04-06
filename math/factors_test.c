#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

extern void factors(int x);

void x_negative(void **state)
{
  expect_assert_failure(factors(-3));
}

void x_positive(void **state)
{
  factors(4);
}

void x_zero(void **state)
{
  expect_assert_failure(factors(0));
}

int main(int argc, char *argv[])
{
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(x_negative),
    cmocka_unit_test(x_positive),
    cmocka_unit_test(x_zero),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}
