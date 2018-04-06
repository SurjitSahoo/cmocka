#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

extern void *mem_copy(void *dest, const void *src, unsigned int n);

const char *buf = "Surjit";

void all_null(void **state)
{
  expect_assert_failure(mem_copy(NULL, NULL, 0));
}

void dest_null(void **state)
{
  expect_assert_failure(mem_copy(NULL, buf, 5));
}

void src_null(void **state)
{
  char *dest = (char*)malloc(10 * sizeof(char));
  expect_assert_failure(mem_copy(dest, NULL, 5));
}

void n_zero(void **state)
{
  char *dest = (char*)malloc(10 * sizeof(char));
  assert_int_equal(strlen(mem_copy(dest, buf, 0)), 0);
}

void all_non_zero(void **state)
{
  char *dest = (char*)malloc(10 * sizeof(char));
  assert_int_equal(strlen(mem_copy(dest, buf, 5)), 5);
}

int main(int argc, char* argv[])
{
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(all_null),
    cmocka_unit_test(dest_null),
    cmocka_unit_test(src_null),
    cmocka_unit_test(n_zero),
    cmocka_unit_test(all_non_zero),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}
