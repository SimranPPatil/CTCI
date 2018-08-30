/*
Given a directed graph, design an algorithm to find out whether there is a route between
two nodes.
*/

/*
Shows how to make maps with user defined objects;
It is important to overload the operator for comparison and sorting if the objects
is to be used in a map;
*/

/*
Here, graph is defined as an adjacency lsit using a map
*/

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>
#include <set>
#include <queue>

using namespace std;

class Node{
public:
  int val;
  Node(int data) : val(data){}
  bool operator < (const Node& userObj) const{
    if(userObj.val < this->val)
      return true;
    return false;
  }
  bool operator == (const Node& userObj) const{
    if(userObj.val == this->val)
      return true;
    return false;
  }
};

void addEdge(map< Node, vector<Node> > &g, int u, int v){
  Node* start = new Node(u);
  Node* neighbor = new Node(v);
  int flag = 0;
  std::map<Node, vector<Node>>::iterator i = g.begin();
  for(; i != g.end(); i++){
    if(i->first.val == u){
      i->second.push_back(*neighbor);
      flag = 1;
      break;
    }
  }
  if(flag == 0){
    vector<Node> temp;
    temp.push_back(*neighbor);
    g[*start] = temp;
  }
}

void print(map< Node, vector<Node> > &g){
  std::map<Node, vector<Node>>::iterator i = g.begin();
  for(; i != g.end(); i++){
    cout << i->first.val << "-> " ;
    for(auto j = i->second.begin(); j != i->second.end(); j++){
      cout << j->val << " ";
    }
    cout << endl;
  }
}

bool BFS(Node start, Node dest, map< Node, vector<Node> > &g){

  if(start == dest)
    return true;

  set<Node> visited;
  queue<Node> q;

  visited.insert(start);
  q.push(start);
  while(!q.empty()){
    Node temp = q.front();
    q.pop();
    vector<Node> neighbors = g[temp];
    for(int i = 0; i < neighbors.size(); i++ ){
      if(neighbors[i] == dest)
        return true;
      if(visited.find(neighbors[i]) == visited.end()){
        visited.insert(neighbors[i]);
        q.push(neighbors[i]);
      }
    }
  }
  return false;
}

int main(){
  map<Node, vector<Node> > g;
  g.insert(make_pair<Node, vector<Node>>(Node(2), vector<Node>{3,4})); // Such declaration is required
  addEdge(g, 5, 6);
  addEdge(g, 5, 7);
  addEdge(g, 5, 8);
  addEdge(g, 4, 5);
  addEdge(g, 5, 4);
  addEdge(g, 3, 4);
  cout << "\nGraph is: " << endl;
  print(g);
  cout << endl;
  Node start = Node(5);
  Node dest = Node(4);
  bool ret = BFS(start,dest,g);
  cout << "Route between nodes " << start.val << " and " << dest.val << " : " << ret << endl;
  return 0;
}
