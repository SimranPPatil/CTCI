/*
Implement an algorithm to delete a node in the middle of a single linked list, given
only access to that node.
EXAMPLE
Input: the node ‘c’ from the linked list a->b->c->d->e
Result: nothing is returned, but the new linked list looks like a->b->d->e
*/

#include <iostream>
#include <stdio.h>

using namespace std;

struct ListNode{
  int val;
  ListNode* next;
  ListNode(int data) : val(data), next(NULL) {}
};

void deletenode(ListNode* toDel, ListNode* head){
  if(toDel == NULL || head == NULL)
    return;

  if(toDel->next == NULL)
    return; // need sentinel ListNode

  toDel->val = toDel->next->val;
  toDel->next = toDel->next->next;
  delete toDel->next;

  return;
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
  cout << endl;

  ListNode* toDel = head;
  for(int i = 0; i < 6; i++){
    toDel = toDel->next;
  }
  cout << "toDel" << toDel->val << endl;
  deletenode(toDel, head);
  curr = head;
  while(curr != NULL){
    cout << curr->val << " ";
    curr = curr->next;
  }

  return 0;
}
