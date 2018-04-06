#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdlib.h>
#include "linkedlst.h"

extern void DeleteList(struct node** headRef);

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
  expect_assert_failure(DeleteList(NULL));
}

void valid_list(void **state)
{
  DeleteList(&a);
  assert_null(a);
}

int main(int argc, char *argv[])
{
  init();
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(null_test),
    cmocka_unit_test(valid_list),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}
