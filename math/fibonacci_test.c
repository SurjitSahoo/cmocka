#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

extern void fibonacci(int n);

void n_zero(void **state)
{
  fibonacci(0);
}

void n_negative(void **state)
{
  expect_assert_failure(fibonacci(-3));
}

void n_positive(void **state)
{
  fibonacci(5);
}

int main(int argc, char* argv[])
{
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(n_zero),
    cmocka_unit_test(n_negative),
    cmocka_unit_test(n_positive),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}

