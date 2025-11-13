#include <stdlib.h>
#include <stdio.h>
struct node{
  int value;
  struct node* next;
};
int deleteNode(struct node *, int);
void displayList(struct node *);
void appendNode(struct node *, int);
int main() {
  struct node *head, *tail;
  int i;
  head = NULL;
  for (i=9; i >= 0; i--) {
    tail =  (struct node *) malloc(sizeof(struct node));
    tail->value = i;
    tail->next = head;      
    head = tail;
  } 
  displayList(head);
  deleteNode(head, 4);
  deleteNode(head, 7);
  puts("\n");
  displayList(head);
  for (i=15; i<20; i++) 
    appendNode(head, i);
  puts("\n");
  displayList(head);
}
int deleteNode(struct node *head, int value) {
  struct node *traverse = head;
  struct node *previous = head;
  int index = 0;
  while(traverse != NULL) {
    if (traverse->value == value) {
      if (traverse == head) 
        head = head->next;
      previous->next = traverse->next;
      free(traverse); 
      return index;
    }
    previous = traverse;
    traverse = traverse->next;
    ++index;   
  }
  return -1; 
}
void displayList(struct node *head) {
  struct node *traverse = head;
  while (traverse != NULL) {
    printf("[Node @ %p] value: %d    next: %p\n",\
           traverse, traverse->value, traverse->next);
    traverse = traverse->next; 
  }  
}
void appendNode(struct node *head, int value) {
  struct node *traverse;
  struct node *tail;
  tail = (struct node *) malloc(sizeof(struct node));
  tail->value = value;
  tail->next = NULL;
  if (head == NULL)
    head = tail;
  else {
    traverse = head;
    while (traverse->next != NULL)
      traverse = traverse->next;
    traverse->next = tail;
  }
}