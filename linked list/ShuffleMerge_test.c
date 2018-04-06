#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdlib.h>
#include "linkedlst.h"

extern struct node* ShuffleMerge(struct node* a, struct node* b);

struct node* a, *d;

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
  struct node* e = (struct node*)malloc(sizeof(struct node));
  struct node* f = (struct node*)malloc(sizeof(struct node));
  d = e;
  e->data = 3;
  e->next = f;
  f->data = 4;
  f->next = NULL;
  
}

void both_null(void **state)
{
  struct node* p = NULL, *q = NULL, *r = NULL;
  r = ShuffleMerge(p, q);
  assert_null(r);
}

void a_null(void **state)
{
  struct node *p = ShuffleMerge(NULL, d);
  assert_int_equal(p->data, 3);
}

void b_null(void **state)
{
  struct node *p = ShuffleMerge(a, NULL);
  assert_int_equal(p->data, 1);
}

void both_valid(void **state)
{
  struct node *p = ShuffleMerge(a, d);
  assert_int_equal(p->data, 1);
  assert_int_equal(p->next->data, 3);
}

int main(int argc, char *argv[])
{
  init();
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(both_null),
    cmocka_unit_test(a_null),
    cmocka_unit_test(b_null),
    cmocka_unit_test(both_valid),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}
