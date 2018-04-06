#include <stdlib.h>
#include "linkedlst.h"
/* Counts the number of times a given integer occurs */
int count(struct node* head, int n)
{
  int c = 0;
  while(head != NULL){
    if(head->data == n) c+=1;
    head = head->next;
  }
  return c;
}
