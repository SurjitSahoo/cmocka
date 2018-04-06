#include <stdlib.h>
#include "linkedlst.h"

/* Deletes the whole list deallocating all of it's
memory and resets the head to NULL */
void DeleteList(struct node** headRef)
{
  struct node *current = *headRef;
  struct node *next;
  while(current != NULL){
    next = current->next;
    free(current);
    current = next;
  }
  *headRef = NULL;
}
