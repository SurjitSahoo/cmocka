#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdlib.h>
#include "linkedlst.h"

extern int countNode(struct node* head);
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

void head_null(void **state)
{
  assert_int_equal(countNode(NULL), 0);
}

void head_not_null(void **state)
{
  assert_int_equal(countNode(a), 3);
}

int main(int argc, char *argv[])
{
  init();
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(head_null),
    cmocka_unit_test(head_not_null),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}
