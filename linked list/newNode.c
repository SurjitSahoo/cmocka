#include <stdlib.h>
#include "linkedlst.h"
/* Create a new node */
struct node *newNode(int data)
{
  struct node* newnode = (struct node*) malloc(sizeof(struct node));
  newnode->data = data;
  newnode->next = NULL;
  return newnode;
}