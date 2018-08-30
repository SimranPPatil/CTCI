/*
Given a sorted (increasing order) array, write an algorithm to create a binary tree with
minimal height.
Runtime: O(log N)
*/

#include <iostream>
#include <stdio.h>

#define LENGTH 10
using namespace std;

class Node{
public:
  int val;
  Node* leftChild;
  Node* rightChild;
  Node(int data) : val(data){}
};

Node* BST(int (&arr)[LENGTH], int left, int right){
  if(right<left)
    return NULL;

  int mid = (right+left)/2;
  if(mid < LENGTH){
    Node* Self = new Node(arr[mid]);
    Self->leftChild = BST(arr, left, mid-1);
    Self->rightChild = BST(arr, mid+1, right);
    return Self;
  }
  return NULL;
}

void print(Node* root){
  if(root == NULL)
    return;
  cout << "self = " << root->val << endl;
  if(root->leftChild != NULL){
    cout << "leftChild: " << root->leftChild->val << endl;
  }
  if(root->rightChild != NULL){
    cout << "rightChild: " << root->rightChild->val << endl;
  }
  print(root->leftChild);
  print(root->rightChild);

}

int main(){

  int arr[LENGTH] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  Node* root = BST(arr, 0, LENGTH);
  print(root);
  return 0;
}
