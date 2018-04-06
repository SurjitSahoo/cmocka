#include <stdlib.h>
#include "linkedlst.h"
/*
Splits the list into two halfs. If the number of nodes are odd
then the extra node goes to the first list.
*/
extern int countNode(struct node* head);
void FrontBackSplit(struct node* source, struct node** frontRef, struct node** backRef)
{
  int len = countNode(source);
  int i;
  struct node* current = source;
  if(len < 2){
    *frontRef = source;
    *backRef = NULL;
  }
  else{
    int hopCount = (len-1)/2;
    for(i = 0; i<hopCount; i++){
      current = current->next;
    }
    *frontRef = source;
    *backRef = current->next;
    current->next = NULL;
  }
}
