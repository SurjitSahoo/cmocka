#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdlib.h>

extern char *strcopy(char *str);

void null_test(void **state)
{
  expect_assert_failure(strcopy(NULL));
}

void not_terminated(void **state)
{
  char s[6] = "surjit";
  assert_string_equal(strcopy(s), "surjit");
}

void terminated(void **state)
{
  char s[] = "surjit\0";
  assert_string_equal(strcopy(s), "surjit");
}

int main(int argc, char *argv[])
{
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(null_test),
    cmocka_unit_test(not_terminated),
    cmocka_unit_test(terminated),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}
