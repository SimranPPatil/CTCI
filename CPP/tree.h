#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>

using namespace std;
template<class T>
struct Node{
  T data;
  Node<T>* right;
  Node* left;
  Node(T newData): data(newData){}
  ~Node(){
    free(right);
    free(left);
  }
};

/*
The tree format array should be:
--> Parent(r) =⌊(r−1)/2⌋ if r≠0.
--> Left child(r) =2r+1 if 2r+1≤n.
--> Right child(r) =2r+2 if 2r+2≤n.
*/
template<class T>
Node<T>* createTree(vector<T> nodes){

  if(nodes.size() == 0)
    return NULL;

  vector< Node<T>* > tree;
  for(int i = 0; i < nodes.size(); i++){
    Node<T>* self = new Node<T>(nodes[i]);
    cout << "self: " << self->data << endl;
    tree.push_back(self);
  }

  for(int i = 0; i < tree.size(); i++){
    if(i*2+1 < tree.size())
      tree[i]->left = tree[i*2+1];
    else
      tree[i]->left = NULL;

    if(i*2+2 < tree.size())
      tree[i]->right = tree[i*2+2];
    else
      tree[i]->right = NULL;
  }

  return tree[0];
}

// Here, tree is created like a Binary tree
template<class T>
Node<T>* createBST(vector<T> arr, int left, int right){
  if(right<left)
    return NULL;

  int mid = (right+left)/2;
  if(mid < arr.size()){
    Node<T>* Self = new Node<T>(arr[mid]);
    Self->left = createBST(arr, left, mid-1);
    Self->right = createBST(arr, mid+1, right);
    return Self;
  }
  return NULL;
}

// Just trying another implementation
template<class T>
Node<T>* createBT(vector<T> arr, int left, int right){

  if(left < right){
    int mid = (right+left)/2;
    Node<T>* Self = new Node<T>(arr[mid]);
    Self->left = createBST(arr, left, mid-1);
    Self->right = createBST(arr, mid+1, right);
    return Self;
  }
  return NULL;
}

template<class T>
void print(Node<T>* root){
  if(root == NULL){
    cout << "done" << endl;
    return;
  }
  cout << "self = " << root->data << endl;
  if(root->left != NULL){
    cout << "leftChild: " << root->left->data << endl;
  }
  if(root->right != NULL){
    cout << "rightChild: " << root->right->data << endl;
  }
  print(root->left);
  print(root->right);
}

template<class T>
Node<T>* deleteTree(Node<T>* &root){
  if(root == NULL)
    return NULL;
  root->left = deleteTree(root->left);
  root->right = deleteTree(root->right);
  if(root->left == NULL && root->right == NULL){
    cout << "deleting: " << root->data << endl;
    delete root;
    root = NULL;
  }
  return root;
}

#endif
