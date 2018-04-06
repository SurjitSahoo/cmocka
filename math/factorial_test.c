#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

extern long int factorial(int x);

void x_zero(void **state)
{
  assert_int_equal(factorial(0), 1);
}

void x_negative(void **state)
{
  expect_assert_failure(factorial(-3));
}

void x_positive(void **state)
{
  assert_int_equal(factorial(4), 24);
}

int main(int argc, char* argv[])
{
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(x_zero),
    cmocka_unit_test(x_negative),
    cmocka_unit_test(x_positive),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}

