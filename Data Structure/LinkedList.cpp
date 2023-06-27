#include <bits/stdc++.h>
using namespace std;
class LinkedList {
 public:
     class Node {
       public:
        int val;
        Node* next;
        Node(int _val, Node* _next) {
         val = _val;
         next = _next;
        }
     };
     int len;
     Node* head = nullptr;
     LinkedList( ) {
      len = 0;
      head = new Node(0, nullptr);
     }
     void insertAtIndex(int index, int val) {
      if(index > len) return;
      Node* curr = head;
      while(index--) {
        curr = curr -> next;
      }
      Node* nextPtr = curr -> next;
      curr -> next = new Node(val, nullptr);
      curr -> next -> next = nextPtr;
      len++;
     }
     void insertAtTail(int val) {
      insertAtIndex(len, val);
     }
     void insertAtHead(int val) {
      insertAtIndex(0, val);
     }
     int getAtIndex(int index) {
      if(index < 0 or index >= len) return -1;
      Node* curr = head -> next;
      while(index--) {
        curr = curr -> next;
      }
      return curr -> val;
     }
};
int main( ) {
  LinkedList myList;
  myList.insertAtHead( 1 );/// 1
  myList.insertAtHead( 2 );///2 1
  myList.insertAtTail( 3 );///2 1 3
  myList.insertAtIndex(1, 4);///2 4 1 3
  cout << myList.getAtIndex( 0 ) << endl;///output shoud be -> 2
  return 0;
}
