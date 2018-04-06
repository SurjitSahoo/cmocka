#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdlib.h>
#include "linkedlst.h"

extern void MoveNode(struct node** destRef, struct node** sourceRef);

struct node* a, *d;

void init()
{
  a = (struct node*)malloc(sizeof(struct node));
  d = (struct node*)malloc(sizeof(struct node));
  struct node* b = (struct node*)malloc(sizeof(struct node));
  struct node* c = (struct node*)malloc(sizeof(struct node));
  a->data = 1;
  a->next = b;
  b->data = 2;
  b->next = c;
  c->data = 2;
  c->next = NULL;
  d->data = 3;
  d->next = NULL;
}

void both_null(void **state)
{
  struct node *p = NULL, *q = NULL;
  MoveNode(&p, &q);
  assert_null(&p);
}

void dest_null(void **state)
{
  struct node *p = NULL, *q;
  q = (struct node*)malloc(sizeof(struct node));
  q->data = 3;
  q->next = NULL;
  MoveNode(&p, &q);
  assert_int_equal(p->data, 3);
  assert_null(q);
  free(q);
}

void src_null(void **state)
{
  struct node* b = (struct node*)malloc(sizeof(struct node));
  struct node* c = NULL;
  b->data = 1;
  b->next = NULL;
  MoveNode(&b, &c);
  assert_null(b->next);
  free(b);
}

void both_valid(void **state)
{
  MoveNode(&a, &d);
  assert_int_equal(a->data, 3);
}

int main(int argc, char* argv[])
{
  init();
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(both_null),
    cmocka_unit_test(dest_null),
    cmocka_unit_test(src_null),
    cmocka_unit_test(both_valid),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}
