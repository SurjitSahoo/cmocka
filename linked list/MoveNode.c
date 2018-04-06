#include <stdlib.h>
#include "linkedlst.h"

/* Takes two lists and moves the 1st node of the 2nd list
 to the head of the 1st list */
extern struct node *newNode(int data);
void MoveNode(struct node** destRef, struct node** sourceRef)
{
  struct node* newNode = *sourceRef;
  if(newNode == NULL) return;
  *sourceRef = newNode->next;
  newNode->next = *destRef;
  *destRef = newNode;
}
