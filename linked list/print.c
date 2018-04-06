#include <stdio.h>
#include <stdlib.h>
#include "linkedlst.h"
/* Prints the list */
void print(struct node *head)
{
  while(head != NULL){
    printf("%d  ", head->data);
    head = head->next;
  }
  printf("\n");
}