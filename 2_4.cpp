/*
You have two numbers represented by a linked list, where each node contains a single
digit. The digits are stored in reverse order, such that the 1’s digit is at the head of
the list. Write a function that adds the two numbers and returns the sum as a linked
list.
EXAMPLE
Input: (3 -> 1 -> 5), (5 -> 9 -> 2)
Output: 8 -> 0 -> 8
*/

#include <iostream>
#include <stdio.h>

using namespace std;

struct ListNode{
  int val;
  ListNode* next;
  ListNode(int data) : val(data), next(NULL) {}
};

void addNums(ListNode* head1, ListNode* head2, ListNode* &output){ // pass pointer by reference too if you want change
  int carry = 0;
  ListNode* curr;
  int nodeVal;
  while(head1 != NULL || head2 != NULL){
    if(head1 != NULL && head2 != NULL){
      nodeVal = head1->val + head2->val + carry;
      head1 = head1->next;
      head2 = head2->next;
    }
    else if(head1 == NULL && head2 != NULL){
      nodeVal = head2->val + carry;
      head2 = head2->next;
    }
    else if(head1 != NULL && head2 == NULL){
      nodeVal = head1->val + carry;
      head1 = head1->next;
    }

    carry = nodeVal/10;
    ListNode* newNode = new ListNode(nodeVal % 10);
    if(output == NULL){
      output = newNode;
      curr = output;
    }
    else{
      curr->next = newNode;
      curr = curr->next;
    }
  }
  if(carry == 1){
    ListNode* newNode = new ListNode(carry);
    curr->next = newNode;
    curr = curr->next;
  }

  cout << "output: " << endl;
  curr = output;
  while(curr != NULL){
    cout << curr->val << " ";
    curr = curr->next;
  }
  cout << endl;

}

int main(){
  ListNode* head1 = NULL;
  ListNode* head2 = NULL;
  ListNode* output = NULL;
  ListNode* curr;
  for(int i = 1; i < 9; i++){
    ListNode* node = new ListNode(i);
    if(head1 == NULL){
      head1 = node;
      curr = head1;
    }
    else{
      curr->next = node;
      curr = curr->next;
    }
  }


  for(int i = 1; i < 10; i++){
    ListNode* node = new ListNode(i%7);
    if(head2 == NULL){
      head2 = node;
      curr = head2;
    }
    else{
      curr->next = node;
      curr = curr->next;
    }
  }

  cout << "List 1: " << endl;
  curr = head1;
  while(curr != NULL){
    cout << curr->val << " ";
    curr = curr->next;
  }
  cout << endl;

  cout << "List 2: " << endl;
  curr = head2;
  while(curr != NULL){
    cout << curr->val << " ";
    curr = curr->next;
  }
  cout << endl;

  // head1 = head2 = NULL;
  addNums(head1, head2, output);
  cout << "output: " << endl;
  curr = output;
  while(curr != NULL){
    cout << curr->val << " ";
    curr = curr->next;
  }
  cout << endl;

  return 0;
}
