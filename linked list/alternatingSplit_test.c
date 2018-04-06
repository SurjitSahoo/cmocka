#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdlib.h>
#include "linkedlst.h"

extern void AlternatingSplit(struct node* source, 
                             struct node** aRef, struct node** bRef);

void source_null(void **state)
{
  struct node** aRef, **bRef;
  expect_assert_failure(AlternatingSplit(NULL, aRef, bRef));
}

void valid_source(void **state)
{
  struct node *src = (struct node*)malloc(sizeof(struct node));
  src->data = 3;
  struct node *s = (struct node*)malloc(sizeof(struct node));
  s->data = 1;
  s->next = NULL;
  src->next = s;
  struct node *aRef = NULL, *bRef = NULL;
  AlternatingSplit(src, &aRef, &bRef);
  assert_int_equal(aRef->data, 3);
  assert_int_equal(bRef->data, 1);
}

int main(int argc, char *argv[])
{
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(source_null),
    cmocka_unit_test(valid_source),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}
