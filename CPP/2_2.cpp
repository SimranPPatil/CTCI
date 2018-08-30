/*
Implement an algorithm to find the nth to last element of a singly linked list.
*/

#include <iostream>
#include <stdio.h>

using namespace std;

struct ListNode{
  int val;
  ListNode* next;
  ListNode(int data) : val(data), next(NULL) {}
};

ListNode* nthTolastBrute(ListNode* head, int n){
  ListNode* curr = head;
  int num_elements = 0;
  while(curr != NULL){
    curr = curr->next;
    num_elements++;
  }

  if(n > num_elements)
    return NULL;

  curr = head;
  int fromstart = num_elements - n;
  while(fromstart-- != 0){
    curr = curr->next;
  }
  return curr;
}

ListNode* nthTolast(ListNode* head, int n){
  if(head == NULL || n < 1)
    return head;
  ListNode* p1 = head;
  ListNode* p2 = head;
  for(int i = 0; i < n-1; i++){
    p2 = p2->next;
    if(p2 == NULL)
      return NULL;
  }
  if(p2->next == NULL)
    return p1;
  else{
    while(p2->next != NULL){
      p1=p1->next;
      p2=p2->next;
    }
  }

  return p1;
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

  curr = nthTolast(head, 7);
  cout << "nth val: " << curr->val;

  return 0;
}
