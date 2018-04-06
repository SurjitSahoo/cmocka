#ifndef _LINK_LINKED_LIST_H
#define _LINK_LINKED_LIST_H


struct node{
  int data;
  struct node *next;
};

/* 
 Counts the number of times a given integer occurs
 in the list
 */
int count(struct node* head, int n);

/* Returns the data value stored at given index */
int GetNth(struct node* head, int index);

/* Deletes the whole list deallocating all of it's
memory and resets the head to NULL */
void DeleteList(struct node** headRef);

/* Deletes the head node and returns the data value of that node */
int pop(struct node **headRef);

/* Inserts a node at given index */
void insertNth(struct node** headRef, int index, int Data);

/* Given a sorted list in increasing order, inserts new node
 to the corect sorted position */
void sortedInsert(struct node** headref, struct node* newnode);

/* Create a new node */
struct node *newNode(int data);

/* Prints the list */
void print(struct node *head);

/* Adds the new node to the begining of the list */
void push(struct node** head_ref, int new_data);

/*Given a list, change it to be in sorted order (using SortedInsert())*/
void InsertSort(struct node** headRef);

/* Takes two lists and appends second list to the end of the first list */
void Append(struct node** aRef, struct node** bRef);

/*
Splits the list into two halfs. If the number of nodes are odd
then the extra node goes to the first list.
*/
void FrontBackSplit(struct node* source, struct node** frontRef, struct node** backRef);

/* Takes a sorted list in increasing order and removes 
 duplicate nodes */
void RemoveDuplicates(struct node* head);

/* Takes two lists and moves the 1st node of the 2nd list
 to the head of the 1st list */
void MoveNode(struct node** destRef, struct node** sourceRef);

/*
Divides a list into two smaller lists, such that the smaller lists
have the alternating nodes of the source list.
*/
void AlternatingSplit(struct node* source, struct node** aRef, struct node** bRef);

/*
Takes two lists and combines them to make one list such that
the new list have alternating nodes of the sorurce lists.
*/
struct node* ShuffleMerge(struct node* a, struct node* b);

/* Takes two soreted lists and merges them to create new sorted list */
struct node *SortedMerge(struct node *a, struct node *b);

/* 
 Splits the list into two halfs and sorts them using 
 FrontBackSplit() and SortedMerge() and finaly merges the
 two lists to get the list sorted 
 */
void MergeSort(struct node** headRef);

/* Given two sorted lists, retrns a new list 
representing the intersection of the two lists */
struct node* SortedIntersect(struct node* a, struct node* b);

/* Reverse a linked list */
void Reverse(struct node** headRef);

/* Counts number of nodes in the list */
int countNode(struct node* head);

#endif
