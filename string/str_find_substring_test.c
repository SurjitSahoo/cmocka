#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdlib.h>
#include <string.h>

extern int str_find_substring(char *str1, char *str2);

void both_null(void **state)
{
  expect_assert_failure(str_find_substring(NULL, NULL));
}

void str1_null(void **state)
{
  expect_assert_failure(str_find_substring(NULL, "surjit"));
}

void str2_null(void **state)
{
  expect_assert_failure(str_find_substring("surjit sahoo", NULL));
}

void unterminated(void **state)
{
  char *p = (char*)malloc(10 * sizeof(char));
  char *q = (char*)malloc(10 * sizeof(char));
  memcpy(p, "surjit", 6);
  memcpy(q, "jit", 3);
  assert_int_equal(str_find_substring(p, q), 3);
  free(p);
  free(q);
}

void terminated(void **state)
{
  assert_int_equal(str_find_substring("surjit", "jit"), 3);
}

void not_found(void **state)
{
  assert_int_equal(str_find_substring("surjit", "jut"), -1);
}

int main()
{
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(both_null),
    cmocka_unit_test(str1_null),
    cmocka_unit_test(str2_null),
    cmocka_unit_test(unterminated),
    cmocka_unit_test(terminated),
    cmocka_unit_test(not_found),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}

