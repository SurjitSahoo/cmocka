#include <stdlib.h>
#include "linkedlst.h"

/* 
 Splits the list into two halfs and sorts them using 
 FrontBackSplit() and SortedMerge() and finaly merges the
 two lists to get the list sorted 
 */
extern void MoveNode(struct node** destRef, struct node** sourceRef);
extern struct node *SortedMerge(struct node *a, struct node *b);
extern void FrontBackSplit(struct node* source, struct node** frontRef, struct node** backRef);

void MergeSort(struct node** headRef)
{
  struct node* head = *headRef;
  struct node* a;
  struct node* b;
  if((head == NULL) || (head->next == NULL)) return;
  FrontBackSplit(head, &a, &b);
  MergeSort(&a);
  MergeSort(&b);
  *headRef = SortedMerge(a, b);
}
