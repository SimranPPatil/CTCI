/*
First Common Ancestor: Design an algorithm and write code to find the first
common ancestor of two nodes in a binary tree. Avoid storing additional nodes
in a data structure. NOTE: This is not necessarily a binary search tree.
*/

#include <iostream>
#include <stdio.h>
#include <vector>
#include "tree.h"
using namespace std;

bool find(Node<int>* root, int node){
  bool flagq, flagr;
  if(root == NULL)
    return false;

  if(root->data == node)
    return true;

  return find(root->left, node) || find(root->right, node);
}

int LCA(Node<int>* root, int q, int r){
  // this works only if both the nodes are present in the given sub tree
  // So have a function that first checks if both nodes are present;
  int ret;
  if(root == NULL)
    return -1;

  if(root->data == q || root->data == r)
    return root->data;

  int left = LCA(root->left, q, r);
  int right = LCA(root->right, q, r);

  if(left != -1 && right != -1)
    return root->data;

  (left == -1) ? (ret = right) : (ret = left);
  return ret;
}

int LeastCommonAncestor(Node<int>* root, int q, int r){
  int lca = LCA(root, q, r);
  (lca == q && find(root, r)) ? (lca) : (lca = -1); // can iterate through the q as root if pointer known
  (lca == r && find(root, q)) ? (lca) : (lca = -1);
  return lca;
}


int main(){
  vector<int> arr;
  for(int i =0; i < 8; i++)
    arr.push_back(i);
  Node<int> * root = createBT(arr, 0, arr.size()-1);
  print(root);
  int q = 0, r = 9;
  int LCA_num = LeastCommonAncestor(root, q, r);
  cout << "LCA for " << q<<", " << r << " : "<< LCA_num << endl;
  return 0;
}
