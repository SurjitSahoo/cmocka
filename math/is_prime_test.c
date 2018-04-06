#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

extern int is_prime(unsigned int x);

void x_zero(void **state)
{
  expect_assert_failure(is_prime(0));
}

void x_negative(void **state)
{
  expect_assert_failure(is_prime(-3));
}

void x_positive(void **state)
{
  assert_int_equal(is_prime(3), 1);
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
