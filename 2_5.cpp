/*
Given a circular linked list, implement an algorithm which returns node at the beginning
of the loop.
DEFINITION
Circular linked list: A (corrupt) linked list in which a node’s next pointer points to an
earlier node, so as to make a loop in the linked list.
EXAMPLE
input: A -> B -> C -> D -> E -> C [the same C as earlier]
output: C
*/

#include <iostream>
#include <stdio.h>
#include <map>

using namespace std;

struct ListNode{
  int val;
  ListNode* next;
  ListNode(int data) : val(data), next(NULL) {}
};

void returnEarliermap(ListNode* head, ListNode* &earlier){
  map<ListNode*, bool> present;
  ListNode* curr = head;
  while(curr != NULL){
    if(present.find(curr) == present.end())
      present[curr] = true;
    else{
      earlier = curr;
      return;
    }
    curr = curr->next;
  }
}

void returnEarlier(ListNode* head, ListNode* &earlier){
  ListNode* n1 = head, *n2 = head;
  while(n2 == NULL || n2->next != NULL ){
    if(n1 != NULL)
    n1 = n1->next;
    if(n2 != NULL)
      n2 = n2->next->next;
    if(n1 == n2)
      break;
  }

  if(n2 == NULL || n2->next == NULL){
    cout << "no loop " << endl;
    earlier = NULL;
    return;
  }

  n1 = head;
  while(n1 != n2){
    n1 = n1->next;
    n2 = n2 -> next;
  }
  earlier = n2;
}

int main(){
  ListNode* head1 = NULL;
  ListNode* curr;
  ListNode* earlier;
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
  curr->next = head1->next->next->next->next->next;

  returnEarlier(head1, earlier);
  cout << "earlier: " << earlier->val <<  " " << earlier <<endl;
  // cout << "List 1: " << endl;
  // curr = head1;
  // while(curr != NULL){
  //   cout << curr->val << " ";
  //   curr = curr->next;
  // }
  // cout << endl;
  curr = head1;
  int encounter = 0;
  while(curr != NULL){
    ListNode* prev = curr;
    // cout << "curr: " << curr << endl;
    if(curr == earlier){
      encounter++;
      cout << "encounter: " << encounter << endl;
    }
    if(encounter == 2)
      break;
    cout << "deleting: " << prev->val << " " <<prev << endl;
    curr = curr->next;
    prev->next = NULL;
    delete prev;
    prev = NULL;
  }
  cout << curr << endl;
  return 0;
}
