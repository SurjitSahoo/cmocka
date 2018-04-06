#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdlib.h>
#include "linkedlst.h"

extern void Append(struct node** aRef, struct node** bRef);

void both_null(void **state)
{
  expect_assert_failure(Append(NULL, NULL));
}

void aRef_null(void **state)
{
  struct node *b = (struct node*)malloc(sizeof(struct node*));
  b->data = 1;
  b->next = NULL;
  struct node *a = NULL;
  Append(&a, &b);
  assert_int_equal(a->data, 1);
}

void both_not_null(void **state)
{
  struct node *a = (struct node*)malloc(sizeof(struct node*));
  a->data = 1;
  a->next = NULL;
  struct node *b = (struct node*)malloc(sizeof(struct node*));
  b->data = 2;
  struct node *c = (struct node*)malloc(sizeof(struct node*));
  b->next = c;
  c->data = 3;
  c->next = NULL;
  Append(&a, &b);
  assert_int_equal(a->next->data, 2);
}

int main(int argc, char *argv[])
{
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(both_null),
    cmocka_unit_test(aRef_null),
    cmocka_unit_test(both_not_null),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}
