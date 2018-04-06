#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdlib.h>
#include "linkedlst.h"

extern void FrontBackSplit(struct node* source, struct node** frontRef, struct node** backRef);
struct node *a = NULL;

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
  struct node *a = NULL, *b = NULL;
  FrontBackSplit(NULL, &a, &b);
  assert_null(a);
  assert_null(b);
}

void not_null(void **state)
{
  struct node *b = NULL, *c = NULL;
  FrontBackSplit(a, &b, &c);
  assert_int_equal(c->data, 2);
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
