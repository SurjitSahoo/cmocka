#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

extern int str_length(char *str);
static char s[10];
void init()
{
  s[0] = 'a';
  s[1] = 'b';
  s[2] = 'c';
  s[3] = 'd';
}

void null_test(void **state)
{
  expect_assert_failure(str_length(NULL));
}

void unterminated_test(void **state)
{
  assert_int_equal(str_length(s), 4);
}

void terminated_test(void **state)
{
  s[4] = '\0';
  assert_int_equal(str_length(s), 4);
}

int main(int argc, char *argv[])
{
  init();
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(null_test),
    cmocka_unit_test(unterminated_test),
    cmocka_unit_test(terminated_test),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}
