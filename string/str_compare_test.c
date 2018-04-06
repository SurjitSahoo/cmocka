#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <string.h>

extern int str_compare(char *a, char *b);

void all_null(void **state)
{
  expect_assert_failure(str_compare(NULL, NULL));
}

void a_null(void **state)
{
  expect_assert_failure(str_compare(NULL, "surjit"));
}

void b_null(void **state)
{
  expect_assert_failure(str_compare("surjit", NULL));
}

void both_unterminated(void **state)
{
  char s[10], p[10];
  memcpy(s, "surjiT", 6);
  memcpy(p, "surjit", 6);
  assert_int_equal(str_compare(s, p), -32);
}

void both_terminated(void **state)
{
  assert_int_equal(str_compare("surjiT", "surjit"), -32);
}

int main(int argc, char* argv[])
{
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(all_null),
    cmocka_unit_test(a_null),
    cmocka_unit_test(b_null),
    cmocka_unit_test(both_unterminated),
    cmocka_unit_test(both_terminated),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}
