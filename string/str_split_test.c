#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdlib.h>
#include <string.h>

extern char **str_split(char *str, char c);

void all_null(void **state)
{
  expect_assert_failure(str_split(NULL, (char)0));
}

void str_null(void **state)
{
  expect_assert_failure(str_split(NULL, 'c'));
}

void char_null(void **state)
{
  char **s = str_split("surjit sahoo", (char)0);
  assert_string_equal(s[0], "surjit sahoo");
}

void unterminated(void **state)
{
  char **s;
  char *p = (char*)malloc(15 * sizeof(char));
  memcpy(p, "surjit sahoo", 11);
  s = str_split(p, ' ');
  assert_string_equal(s[0], "surjit");
  free(p);
}

void terminated(void **state)
{
  char **s;
  char *p = (char*)malloc(15 * sizeof(char));
  memcpy(p, "surjit sahoo\0", 12);
  s = str_split(p, ' ');
  assert_string_equal(s[0], "surjit");
  free(p);
}

int main(int argc, char* argv[])
{
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(all_null),
    cmocka_unit_test(str_null),
    cmocka_unit_test(char_null),
    cmocka_unit_test(unterminated),
    cmocka_unit_test(terminated),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}
