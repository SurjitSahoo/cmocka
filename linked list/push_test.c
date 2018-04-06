#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdlib.h>
#include "linkedlst.h"

extern void push(struct node** head_ref, int new_data);


void not_null(void **state)
{
  struct node *a = (struct node*)malloc(sizeof(struct node));
  a->data = 1;
  a->next = NULL;
  push(&a, 0);
  assert_int_equal(a->data, 0);
  free(a);
}

void head_null(void **state)
{
  struct node *p = NULL;
  push(&p, 0);
  assert_int_equal(p->data, 0);
}

int main(int argc, char* argv[])
{
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(not_null),
    cmocka_unit_test(head_null),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}
