/*
Write code to remove duplicates from an unsorted linked list.
FOLLOW UP
How would you solve this problem if a temporary buffer is not allowed?
*/

#include <iostream>
#include <stdio.h>
#include <map>

using namespace std;

struct ListNode{
  int val;
  ListNode* next;
  ListNode(int data): val(data), next(NULL){}
};

void removeDuplicate(ListNode* head){
  map<int, bool> present;
  ListNode* curr  = head;
  while(curr != NULL){
    int val = curr->val;
    cout << "val: " << val << endl;
    if(present.find(val) == present.end()){
      present[val] = true;
      cout << "curr: " << curr->val << endl;
      curr = curr->next;
    }
    else{
      // delete the node
      if(curr->next != NULL){
        curr->val = curr->next->val;
        curr->next = curr->next->next;
        delete curr->next;
      }
    }
  }
}

void removeDuplicateWOBuff(ListNode* head){
  // another method, check for earlier dups
  ListNode* curr  = head;
  while(curr != NULL){
    ListNode* checker = curr->next;
    int val = curr->val;
    cout << "val: " << val << endl;
    while(checker != NULL){
      if(checker->val == val){
        if(checker->next != NULL){
          checker->val = checker->next->val;
          checker->next = checker->next->next;
          delete checker->next;
        }
      }
      checker = checker->next;
    }
    curr = curr->next;
  }
}

int main(){
  ListNode* head = NULL;
  ListNode* curr;
  for(int i = 0; i < 5; i++){
    ListNode* node = new ListNode(i);
    if(head == NULL){
      head = node;
      curr = head;
    }
    else{
      curr->next = node;
      curr = curr->next;
    }
  }
  for(int i = 0; i < 7; i++){
    ListNode* node = new ListNode(i);
    if(head == NULL){
      head = node;
      curr = head;
    }
    else{
      curr->next = node;
      curr = curr->next;
    }
  }

  curr = head;
  while(curr != NULL){
    cout << curr->val << " ";
    curr = curr->next;
  }
  cout << "After: " << endl;
  removeDuplicateWOBuff(head);
  curr = head;
  while(curr != NULL){
    cout << curr->val << " ";
    curr = curr->next;
  }
  return 0;
}
