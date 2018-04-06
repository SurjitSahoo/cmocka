#include <stdlib.h>
#include "linkedlst.h"
/* Deletes the head node and returns the data value of that node */
int pop(struct node **headRef)
{
  int ans;
  struct node *head = *headRef;
  if(head == NULL) return 0;
  ans = head->data;
  *headRef = head->next;
  free(head);
  return(ans);
}
