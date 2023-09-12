#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
 int data;
 struct Node* nextptr;
}Node;
void createNode(Node* dummyHead, int value) {
  Node *newNode = malloc(sizeof(Node));
  newNode ->  data = value;
  newNode -> nextptr = NULL;
  Node* helper = dummyHead;
  while(helper -> nextptr != NULL) {
    helper = helper -> nextptr;
  }
  helper -> nextptr = newNode;
}
void insertAtHead(Node* dummyHead, int value) {
  Node* helper = dummyHead -> nextptr;
  Node *newNode = malloc(sizeof(Node));
  newNode -> data = value;
  newNode -> nextptr = helper -> nextptr;
  helper -> nextptr = newNode;
}
void insertAtTail(Node* dummyHead, int value) {
  Node *newNode = malloc(sizeof(Node));
  newNode ->  data = value;
  newNode -> nextptr = NULL;
  Node* helper = dummyHead;
  while(helper -> nextptr != NULL) {
    helper = helper -> nextptr;
  }
  helper -> nextptr = newNode;
}
void printNode(Node* dummyHead) {
  if(dummyHead == NULL) return;
  Node* helper = dummyHead -> nextptr;
  while(helper -> nextptr != NULL) {
    printf("%d ", helper -> nextptr -> data);
    helper = helper -> nextptr;
  }
  printf("\n");
}
void searchNode(Node* dummyHead, int key) {
  if(dummyHead == NULL) {
    printf("Not Found!\n");
   return;
  }
  int flag = 0;
  Node* helper = dummyHead -> nextptr;
  while(helper -> nextptr != NULL) {
    if(helper -> nextptr -> data == key) {
     flag = 1;
     break;
    }
    helper = helper -> nextptr;
  }
  printf(flag ? "Found\n" : "Not Found\n");
}
void deleteHead(Node* dummyHead) {
 if(dummyHead == NULL) return;
 dummyHead -> nextptr = dummyHead -> nextptr -> nextptr;
}
void deleteTail(Node* dummyHead) {
  Node* helper = dummyHead;
  while(helper -> nextptr -> nextptr != NULL) {
    helper = helper -> nextptr;
  }
  helper -> nextptr = helper -> nextptr -> nextptr;
}
void deleteAtPosition(Node* dummyHead, int index) {
 Node* helper = dummyHead;
 while(index--) {
  helper = helper -> nextptr;
 }
 helper -> nextptr = helper -> nextptr -> nextptr;
}
void insertAtPosition(Node* dummyHead, int value, int index) {
  Node *newNode = malloc(sizeof(Node));
  newNode ->  data = value;
  newNode -> nextptr = NULL;
  Node* helper = dummyHead;
  while(index--) {
    helper = helper -> nextptr;
  }
  Node* nextTrack = helper -> nextptr;
  helper -> nextptr = newNode;
  newNode -> nextptr = nextTrack;
}
int main( ) {
  Node *dummyHead = NULL;
  ///create nodes
  createNode(&dummyHead, 5);
  createNode(&dummyHead, 7);
  ///Printing the nodes
  printNode(&dummyHead);
  ///insert at the beginning
  insertAtHead(&dummyHead, 2);
  insertAtHead(&dummyHead, 8);
  printNode(&dummyHead);
  ///insert at the last
  insertAtTail(&dummyHead, 9);
  insertAtTail(&dummyHead, 11);
  printNode(&dummyHead);
  ///search an element
  searchNode(&dummyHead, 5);
  ///delete the first element
  deleteHead(&dummyHead);
  printNode(&dummyHead);
  ///delete the last element
  deleteTail(&dummyHead);
  printNode(&dummyHead);
  ///delete at any position
  deleteAtPosition(&dummyHead, 3);
  printNode(&dummyHead);
  ///Insert at any position
  insertAtPosition(&dummyHead, 12, 3);
  printNode(&dummyHead);
  return 0;
}
