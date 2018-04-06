#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdio.h>

extern void evenOrOdd(int x);

void x_zero(void **state)
{
  evenOrOdd(0);
}

void x_negative(void **state)
{
  evenOrOdd(-3);
}

void x_positive(void **state)
{
  evenOrOdd(4);
}

int main(int argc, char *argv[])
{
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(x_zero),
    cmocka_unit_test(x_negative),
    cmocka_unit_test(x_positive),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}
