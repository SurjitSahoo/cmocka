#include <stdlib.h>
#include <assert.h>
#include "linkedlst.h"

//#ifdef UNIT_TESTING
extern void mock_assert(const int result, const char* const expression, 
                        const char * const file, const int line);
#undef assert
#define assert(expression) \
    mock_assert((int)(expression), #expression, __FILE__, __LINE__);
//#endif // UNIT_TESTING

/*
Divides a list into two smaller lists, such that the smaller lists
have the alternating nodes of the source list.
*/
void AlternatingSplit(struct node* source, struct node** aRef, struct node** bRef)
{
  assert(source != NULL);
  struct node* a = NULL;
  struct node* b = NULL;
  struct node* current = source;
  while(current != NULL){
    MoveNode(&a, &current);
    if(current != NULL) MoveNode(&b, &current);
  }
  *aRef = a;
  *bRef = b;
}
 
