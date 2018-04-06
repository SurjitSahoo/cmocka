#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

extern int gcd(int a, int b);

void a_zero(void **state)
{
  assert_int_equal(gcd(0, 4), 0);
}

void b_zero(void **state)
{
  assert_int_equal(gcd(4, 0), 0);
}

void a_negative(void **state)
{
  assert_int_equal(gcd(-4, 8), 0);
}

void b_negative(void **state)
{
  assert_int_equal(gcd(4, -8), 0);
}

void all_positive(void **state)
{
  assert_int_equal(gcd(4, 8), 4);
}

int main(int argc, char *argv[])
{
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(a_zero),
    cmocka_unit_test(b_zero),
    cmocka_unit_test(a_negative),
    cmocka_unit_test(b_negative),
    cmocka_unit_test(all_positive),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}
