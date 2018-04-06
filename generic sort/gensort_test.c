#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

extern void* Sort(void* arr, int (*compareFcn)(void*, void*), 
                  int sizeOfElement, int numElements);
/************************************************************/
/** Int Comparison **/
int CompIntAscending(void *x, void *y)
{
  int a = *((int*)x);
  int b = *((int*)y);
  if(a > b) return 1;
  else return -1;
}
int CompIntDescending(void *x, void *y)
{
  int a = *((int*)x);
  int b = *((int*)y);
  if(a > b) return -1;
  else return 1;
}

/** Float Comparison **/
int CompFloatAscending(void *x, void *y)
{
  float a = *((float*)x);
  float b = *((float*)y);
  if(a > b) return 1;
  else return -1;
}
int CompFloatDescending(void *x, void *y)
{
  float a = *((float*)x);
  float b = *((float*)y);
  if(a > b) return -1;
  else return 1;
}

/** Char Comparison **/
int CompCharAscending(void *x, void *y)
{
  char a = *((char*)x);
  char b = *((char*)y);
  if(a > b) return 1;
  else return -1;
}
int CompCharDescending(void *x, void *y)
{
  char a = *((char*)x);
  char b = *((char*)y);
  if(a > b) return -1;
  else return 1;
}
/**  string comparison **/
int CompStrAscending(void *x, void *y)
{
  char *a = (char*)x;
  char *b = (char*)y;
  int c1 = 0, c2 = 0, cmp = 0, i = 0;
  while(a[c1] != '\0') c1 += 1;
  while(b[c2] != '\0') c2 += 1;
  while((i < c1) && (i < c2)){
    if(a[i] == b[i]){
      i++;
      continue;
    }
    if(a[i] < b[i]){
      cmp = (-1);
      break;
    }
    if(a[i] > b[i]){
      cmp = 1;
      break;
    }
  }
  return cmp;
}
int CompStrDecending(void *x, void *y)
{
  char *a = (char*)x;
  char *b = (char*)y;
  int c1 = 0, c2 = 0, cmp = 0, i = 0;
  while(a[c1] != '\0') c1 += 1;
  while(b[c2] != '\0') c2 += 1;
  while((i < c1) && (i < c2)){
    if(a[i] == b[i]){
      i++;
      continue;
    }
    if(a[i] < b[i]){
      cmp = 1;
      break;
    }
    if(a[i] > b[i]){
      cmp = (-1);
      break;
    }
  }
  return cmp;
}
/***************************************************/
void all_null(void **state)
{
  assert_null(Sort(NULL, NULL, 0,0));
}

void compare_null(void **state)
{
  int a[] = {1, 2, 3};
  assert_null(Sort(a, NULL, sizeof(int), 3));
}

void sizeofelement_zero(void **state)
{
  int a[] = {1, 4, 2};
  assert_null(Sort(a, CompIntAscending, 0, 3));
}

void arr_null(void **state)
{
  assert_null(Sort(NULL, CompIntAscending, sizeof(int), 3));
}

void noOfelements_zero(void **state)
{
  int a[] = {1, 4, 3};
  assert_null(Sort(a, CompIntAscending, sizeof(int), 0));
}

void intAsc(void **state)
{
  int a[] = {1, 4, 3};
  Sort(a, CompIntAscending, sizeof(int), 3);
  assert_int_equal(a[1], 3);
}

void intDes(void **state)
{
  int a[] = {1, 4, 3};
  Sort(a, CompIntDescending, sizeof(int), 3);
  assert_int_equal(a[1], 3);
} 

void floatAsc(void **state)
{
  float a[] = {1.2, 4.2, 3.4};
  Sort(a, CompFloatAscending, sizeof(float), 3);
  assert_int_equal((int)a[2], 4);
}

void floatDes(void **state)
{
  float a[] = {1.2, 4.2, 3.4};
  Sort(a, CompFloatDescending, sizeof(float), 3);
  assert_int_equal((int)a[2], 1);
}

void charAsc(void **state)
{
  char a[] = {'a', 'c', 'b'};
  Sort(a, CompCharAscending, sizeof(char), 3);
  assert_int_equal((int)a[0], 97);
}

void charDes(void **state)
{
  char a[] = {'a', 'c', 'b'};
  Sort(a, CompCharDescending, sizeof(char), 3);
  assert_int_equal((int)a[0], 99);
}

/************************************************/
int main(int argc, char *argv[])
{
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(all_null),
    cmocka_unit_test(compare_null),
    cmocka_unit_test(sizeofelement_zero),
    cmocka_unit_test(arr_null),
    cmocka_unit_test(noOfelements_zero),
    cmocka_unit_test(intAsc),
    cmocka_unit_test(intDes),
    cmocka_unit_test(floatAsc),
    cmocka_unit_test(floatDes),
    cmocka_unit_test(charAsc),
    cmocka_unit_test(charDes),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}
