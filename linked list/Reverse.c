#include <stdio.h>
#include <stdlib.h>
#include "linkedlst.h"
void Reverse(struct node** headRef)
{
  struct node* result = NULL;
  struct node* current = *headRef;
  struct node* next;
  while (current != NULL){
    next = current->next;
    current->next = result;
    result = current;
    current = next;
  }
  *headRef = result;
}
