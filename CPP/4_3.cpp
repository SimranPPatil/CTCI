/*
List of Depths: Given a binary tree, design an algorithm which creates a linked list
of all the nodes at each depth (e.g., if you have a tree with depth D, you'll have Dlinked lists).
*/

#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <utility>
#include <map>

#include "tree.h"
using namespace std;

void createLists(Node<int> * root, vector<vector<Node<int>*> > &lists){
  map<Node<int>*, int> visited;
  queue<Node<int>*> nodes;

  if(visited.find(root) == visited.end())
    visited.insert(make_pair(root, 0));
  lists[0].push_back(root);
  nodes.push(root);

  while(!nodes.empty()){
    Node<int>* curr = nodes.front();
    nodes.pop();
    Node<int>* left = curr->left;
    Node<int>* right = curr->right;
    int level = visited[curr];
    if(left != NULL && visited.find(left) == visited.end()){
      visited.insert(make_pair(left, level+1));
      nodes.push(left);
      lists[level+1].push_back(left);
    }
    if(right != NULL && visited.find(right) == visited.end()){
      visited.insert(make_pair(right, level+1));
      nodes.push(right);
      lists[level+1].push_back(right);
    }
  }
}

int main(){
  vector<int> arr;
  for(int i = 1; i < 8; i++){
    arr.push_back(i);
  }
  Node<int> * root = createBT(arr, 0, arr.size()-1);
  print(root);
  vector<vector<Node<int>*> > lists(arr.size(), std::vector<Node<int>*>() );
  createLists(root, lists);
  for(int i = 0; i < lists.size(); i++){
    vector<Node<int>*> temp = lists[i];
    if(temp.size()){
      cout << "level: " << i << endl;
      for(int j = 0; j < temp.size(); j++){
        //if(temp[j] != NULL)
        cout << "node: " << temp[j]->data << endl;
      }
    }

  }
  return 0;
}
