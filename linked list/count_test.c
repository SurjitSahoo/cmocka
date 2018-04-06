#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdlib.h>
#include "linkedlst.h"

extern int count(struct node* head, int n);
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

void both_null(void **state)
{
  assert_int_equal(count(NULL, 0), 0);
}

void n_zero(void **state)
{
  assert_int_equal(count(a, 0), 0);
}

void both_valid(void **state)
{
  assert_int_equal(count(a, 2), 2);
}

int main(int argc, char *argv[])
{
  init();
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(both_null),
    cmocka_unit_test(n_zero),
    cmocka_unit_test(both_valid),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}
