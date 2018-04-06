#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdlib.h>
#include "linkedlst.h"

extern int GetNth(struct node* head, int index);

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
  expect_assert_failure(GetNth(NULL, 2));
}

void not_null(void **state)
{
  assert_int_equal(GetNth(a, 2), 2);
}

int main(int argc, char* argv[])
{
  init();
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(null_test),
    cmocka_unit_test(not_null),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}
  
