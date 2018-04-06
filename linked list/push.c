#include <stdlib.h>
#include "linkedlst.h"
/* Adds the new node to the begining of the list */
void push(struct node** head_ref, int new_data)
{
  struct node* new_node = (struct node*) malloc(sizeof(struct node));
  new_node->data = new_data;
  new_node->next = (*head_ref);
  (*head_ref)    = new_node;
}