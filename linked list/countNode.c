#include <stdlib.h>
#include "linkedlst.h"

/* Counts number of nodes in the list */
int countNode(struct node* head)
{
  int c = 0;
  while(head != NULL){
    c+=1;
    head = head->next;
  }
  return c;
}
