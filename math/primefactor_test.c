#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

extern void primefactor(unsigned int x);

void x_zero(void **state)
{
  expect_assert_failure(primefactor(0));
}

void x_negative(void **state)
{
  expect_assert_failure(primefactor(-10));
}

void x_positive(void **state)
{
  primefactor(10);
}

int main(int argc, char *argv[])
{
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(x_zero),
    cmocka_unit_test(x_negative),
    cmocka_unit_test(x_positive),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}
