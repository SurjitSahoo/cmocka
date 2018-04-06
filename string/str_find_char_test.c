#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdlib.h>
#include <string.h>

extern int str_find_char(char *str, char *ch);

void both_null(void **state)
{
  assert_int_equal(str_find_char(NULL, NULL), -1);
}

void str_null(void **state)
{
  char c = 'a';
  assert_int_equal(str_find_char(NULL, &c), -1);
}

void char_null(void **state)
{
  char *s = "surjit";
  assert_int_equal(str_find_char(s, NULL), -1);
}

void unterminated(void **state)
{
  char *p = "surjit";
  char c = 's';
  char *s = (char*)malloc(10 * sizeof(char));
  memcpy(s, p, 6);
  assert_int_equal(str_find_char(s, &c), 1);
  free(s);
}

void terminated(void **state)
{
  char *s = "surjit";
  char c = 's';
  assert_int_equal(str_find_char(s, &c), 1);
}

int main(int argc, char *argv[])
{
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(both_null),
    cmocka_unit_test(str_null),
    cmocka_unit_test(char_null),
    cmocka_unit_test(unterminated),
    cmocka_unit_test(terminated),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}
