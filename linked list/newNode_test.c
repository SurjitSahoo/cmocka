#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdlib.h>
#include "linkedlst.h"

extern struct node *newNode(int data);

void null(void **state)
{
  struct node *a = newNode(0);
  assert_int_equal(a->data, 0);
}

int main(int argc, char* argv[])
{
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(null),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}
