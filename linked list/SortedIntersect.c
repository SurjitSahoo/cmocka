#include <stdlib.h>
#include "linkedlst.h"

/* Given two sorted lists, retrns a new list 
representing the intersection of the two lists */
extern void push(struct node** head_ref, int new_data);
struct node* SortedIntersect(struct node* a, struct node* b)
{
  struct node dummy;
  struct node *tail = &dummy;
  dummy.next = NULL;
  while(a!=NULL && b!=NULL){
    if(a->data == b->data){
      push((&tail->next), a->data);
      tail = tail->next;
      a = a->next;
      b = b->next;
    }
    else if(a->data < b->data) a = a->next;
    else b = b->next;
  }
  return(dummy.next);
}
