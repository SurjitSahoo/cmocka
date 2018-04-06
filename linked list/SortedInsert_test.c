#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdlib.h>
#include "linkedlst.h"

extern void sortedInsert(struct node** headref, struct node* newnode);

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

void a_null(void **state)
{
  struct node* p = NULL;
  struct node q;
  q.data = 5;
  q.next = NULL;
  sortedInsert(&p, &q);
  assert_int_equal(p->data, 5);
}

void b_null(void **state)
{
  struct node *p = NULL;
  sortedInsert(&a, p);
  assert_int_equal(a->data, 1);
  assert_int_equal(a->next->data, 2);
  assert_int_equal(a->next->next->data, 2);
}

void both_valid(void **state)
{
  struct node p;
  p.data = 3;
  p.next = NULL;
  sortedInsert(&a, &p);
  assert_int_equal(a->next->next->next->data, 3);
}

int main(int argc, char* argv[])
{
  init();
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(a_null),
    cmocka_unit_test(b_null),
    cmocka_unit_test(both_valid),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}
