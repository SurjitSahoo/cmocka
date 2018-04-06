#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

extern int lcm(int a, int b, int c);

void all_zero(void **state)
{
  expect_assert_failure(lcm(0,0,0));
}

void a_zero(void **state)
{
  expect_assert_failure(lcm(0, 2, 3));
}

void b_zero(void **state)
{
  expect_assert_failure(lcm(2, 0, 3));
}

void c_zero(void **state)
{
  expect_assert_failure(lcm(2, 3, 0));
}

void all_negative(void **state)
{
  expect_assert_failure(lcm(-1, -2, -3));
}

void a_negative(void **state)
{
  expect_assert_failure(lcm(-1, 2, 3));
}

void b_negative(void **state)
{
  expect_assert_failure(lcm(1, -2, 3));
}

void c_negative(void **state)
{
  expect_assert_failure(lcm(1, 2, -3));
}

void all_positive(void **state)
{
  assert_int_equal(lcm(1, 2, 3), 6);
}

int main(int argc, char* argv[])
{
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(all_zero),
    cmocka_unit_test(a_zero),
    cmocka_unit_test(b_zero),
    cmocka_unit_test(c_zero),
    cmocka_unit_test(all_negative),
    cmocka_unit_test(a_negative),
    cmocka_unit_test(b_negative),
    cmocka_unit_test(c_negative),
    cmocka_unit_test(all_positive),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}

