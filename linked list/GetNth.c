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

/* Returns the data value stored at given index */
int GetNth(struct node* head, int index)
{
  assert(head != NULL);
  int i;
  for(i = 0; (i <= index) && (head != NULL); i++){
    if(i == index) return head->data;
    head = head->next;
  }
  return 0;
}
