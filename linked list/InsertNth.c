#include <stdio.h>
#include <stdlib.h>
#include "linkedlst.h"
/* Inserts a node at given index */
void insertNth(struct node** headRef, int index, int Data)
{
  int distanceFromHead = 1;
  struct node* head = *headRef;
  struct node* temp1 = (struct node*)malloc(sizeof(struct node));
  temp1->data = Data;
  if(index == 0){
    temp1->next = head;
    *headRef = temp1;
    return;
  }
  while(head != NULL){
    if(distanceFromHead == index){
      temp1->next = head->next;
      head->next = temp1;
    }
    head = head->next;
    distanceFromHead++;
  }
  /* For error handling */
  if(head == NULL && distanceFromHead < index) {
    printf("Error!! \nCan't add %d at position %d \nTry Again\n", Data, index);
  }
}
