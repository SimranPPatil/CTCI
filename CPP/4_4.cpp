/*
Implement a function to check if a tree is balanced. For the purposes of this question,
a balanced tree is defined to be a tree such that no two leaf nodes differ in distance
from the root by more than one.
*/

#include <iostream>
#include <stdio.h>
#include "tree.h"
#include <vector>

using namespace std;

int checkBalanced(Node<int> * root){
  if(root == NULL)
    return 0;

  int left = 0, right = 0, height = 0;
  if(root->left)
    left = checkBalanced(root->left);

  if(root->right)
    right = checkBalanced(root->right);

  if(root->right == NULL && root->left==NULL)
    height = 1;
  else{
    if(abs(left-right) > 1 || left == -1 || right == -1)
      height = -1;
    else
      height = max(left, right) + 1;
  }

    cout << "left: " << left << " right: " << right << endl;
    cout << "root: " << root->data << " height: " << height << endl;
    return height;
}


int main(){
  vector<int> arr;
  for(int i = 1; i < 9; i++){
    arr.push_back(i);
  }
  arr.push_back(10);
  arr.push_back(14);
  arr.push_back(22);
  arr.push_back(29);

  Node<int> * root = createTree(arr);
  Node<int>* curr = root;
  while(curr->right != NULL)
    curr = curr->right;
  curr->right = new Node<int>(56);
  curr = curr->right;
  curr->left = new Node<int>(78);
  print(root);
  int res = checkBalanced(root);
  cout << res << endl;

  return 0;
}
