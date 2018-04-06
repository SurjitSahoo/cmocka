#include <stdlib.h>
extern void *mem_copy(void *dest, const void *src, unsigned int n);
extern int CompIntAscending(void *x, void *y);
extern int CompIntDescending(void *x, void *y);
extern int CompFloatAscending(void *x, void *y);
extern int CompFloatDescending(void *x, void *y);
extern int CompCharAscending(void *x, void *y);
extern int CompCharDescending(void *x, void *y);
extern int CompStrAscending(void *x, void *y);
extern int CompStrDecending(void *x, void *y);

void* Sort(void* arr, int (*compareFcn)(void*, void*), int sizeOfElement, int numElements)
{
  if(!arr || !compareFcn || !numElements || !sizeOfElement)
    return NULL;

  int i, j ;
  void *temp = calloc(1, sizeOfElement);
  for(i = 0; i < numElements; i++)
    for(j = i+1; j < numElements; j++)
      /* Compare two consecutive elements */
      if(compareFcn((((char*)arr) + (i*sizeOfElement)),
                    (((char*)arr) + (j*sizeOfElement)) ) > 0){
        mem_copy(temp, (((char*)arr) + (i*sizeOfElement)), sizeOfElement);
        mem_copy((((char*)arr) + (i*sizeOfElement)),
                 (((char*)arr) + (j*sizeOfElement)), sizeOfElement);
        mem_copy((((char*)arr) + (j*sizeOfElement)), temp, sizeOfElement);
      }
  free(temp);
  return arr;
}
