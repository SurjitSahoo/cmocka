#include <stdlib.h>
#include "linkedlst.h"

/*
Takes two lists and combines them to make one list such that
the new list have alternating nodes of the sorurce lists.
*/
extern void MoveNode(struct node** destRef, struct node** sourceRef);
struct node* ShuffleMerge(struct node* a, struct node* b)
{
  struct node temp;
  struct node* tail = &temp;
  temp.next = NULL;
  while (1){
    if(a==NULL){
      tail->next = b;
      break;
    }
    else if(b==NULL){
      tail->next = a;
      break;
    }
    else{
      MoveNode(&(tail->next), &a);
      tail = tail->next;
      MoveNode(&(tail->next), &b);
      tail = tail->next;
    }
  }
  return(temp.next);
}
