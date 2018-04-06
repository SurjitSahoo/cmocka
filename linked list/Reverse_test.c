#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdlib.h>
#include "linkedlst.h"

extern void Reverse(struct node** headRef);

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

void null_test(void **state)
{
  struct node* p = NULL;
  Reverse(&p);
  assert_null(p);
}

void not_null(void **state)
{
  Reverse(&a);
  assert_int_equal(a->data, 2);
  assert_int_equal(a->next->data, 2);
  assert_int_equal(a->next->next->data, 1);
}

int main(int argc, char *argv[])
{
  init();
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(null_test),
    cmocka_unit_test(not_null),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}

