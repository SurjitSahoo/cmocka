#include <stdlib.h>
#include "linkedlst.h"

/* Takes two soreted lists and merges them to create new sorted list */
struct node *SortedMerge(struct node *a, struct node *b)
{
  struct node dummy;
  struct node *tail = &dummy;
  dummy.next = NULL;
  while(1){
    if(a == NULL){
      tail->next = b;
      break;
    }
    else if(b == NULL){
      tail->next = a;
      break;
    }
    if(a->data <= b->data)
      MoveNode(&(tail->next), &a);
    else MoveNode(&(tail->next), &b);
    tail = tail->next;
  }
  return(dummy.next);
}