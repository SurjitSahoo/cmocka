#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

extern double power(double base, int exp);

void base_zero(void **state)
{
  assert_int_equal(power(0, 3), 0);
}

void exp_zero(void **state)
{
  assert_int_equal(power(3, 0), 1);
}

int main(int argc, char *argv[])
{

  const struct CMUnitTest tests[] = {
    cmocka_unit_test(base_zero),
    cmocka_unit_test(exp_zero),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
  
}
