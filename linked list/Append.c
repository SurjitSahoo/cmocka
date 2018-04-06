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

/* Takes two lists and appends second list to the end of the first list */
void Append(struct node** aRef, struct node** bRef)
{
  assert(aRef != NULL && bRef != NULL);
  struct node* current;
  if(*aRef == NULL) *aRef = *bRef;
  else{
    current = *aRef;
    while (current->next != NULL) current = current->next;
    current->next = *bRef;
  }
  *bRef=NULL;
}
