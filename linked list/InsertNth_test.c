#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdlib.h>
#include "linkedlst.h"

extern void insertNth(struct node** headRef, int index, int Data);

struct node* a;

void init()
{
  a = (struct node*)malloc(sizeof(struct node));
  struct node* b = (struct node*)malloc(sizeof(struct node));
  struct node* c = (struct node*)malloc(sizeof(struct node));
  a->data = 1;
  a->next = b;
  b->data = 2;
  b->next = c;
  c->data = 2;
  c->next = NULL;
}

void bigger_index(void **state)
{
  insertNth(&a, 5, 4);
  assert_int_equal(a->next->next->next->data, 4);
}

void null_test(void **state)
{
  struct node *b = NULL;
  insertNth(&b, 0, 2);
  assert_int_equal(b->data, 2);
}

void not_null(void **state)
{
  insertNth(&a, 0, 0);
  assert_int_equal(a->data, 0);
}

int main(int argc, char *argv[])
{
  init();
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(null_test),
    cmocka_unit_test(bigger_index),
    cmocka_unit_test(not_null),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}
