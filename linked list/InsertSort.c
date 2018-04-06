#include <stdlib.h>
#include "linkedlst.h"
/*Given a list, change it to be in sorted order (using SortedInsert())*/
extern void sortedInsert(struct node** headref, struct node* newnode);
void InsertSort(struct node** headRef)
{
  struct node* result = NULL;
  struct node* current = *headRef;
  struct node* next;
  while (current!=NULL){
    next = current->next;
    sortedInsert(&result, current);
    current = next;
  }
  *headRef = result;
}
