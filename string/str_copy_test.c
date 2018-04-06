#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdlib.h>
#include <string.h>

extern int str_copy(char *str1, char *str2);
char *p, *q;

void all_null(void **state)
{
  expect_assert_failure(str_copy(NULL, NULL));
}

void str1_null(void **state)
{
  p = (char*)malloc(10 * sizeof(char));
  strcpy(p,"surjit");
  expect_assert_failure(str_copy(NULL, p));
  free(p);
}

void str2_null(void **state)
{
  q = (char*)malloc(10 * sizeof(char));
  expect_assert_failure(str_copy(q, NULL));
}

void not_terminated(void **state)
{
  p = (char*)malloc(10 * sizeof(char));
  q = (char*)malloc(10 * sizeof(char));
  p[0] = 's';
  p[1] = 'u';
  assert_int_equal(str_copy(q, p), 0);
  free(p);
  free(q);
}

void terminated(void **state)
{
  p = (char*)malloc(10 * sizeof(char));
  q = (char*)malloc(10 * sizeof(char));
  strcpy(p, "surjit\0");
  assert_int_equal(str_copy(q, p), 0);
  free(p);
  free(q);
}

void not_enough_memory(void **state)
{
  p = (char*)malloc(sizeof(char));
  q = (char*)malloc(10 * sizeof(char));
  strcpy(p, "surjit\0");
  assert_int_equal(str_copy(q, p), -1);
  free(p);
  free(q);
}

int main(int argc, char *argv[])
{
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(all_null),
    cmocka_unit_test(str2_null),
    cmocka_unit_test(str1_null),
    cmocka_unit_test(not_terminated),
    cmocka_unit_test(terminated),
    cmocka_unit_test(not_enough_memory),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}
