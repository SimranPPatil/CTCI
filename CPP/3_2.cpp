/*
How would you design a stack which, in addition to push and pop, also has a function
min which returns the minimum element? Push, pop and min should all operate in
O(1) time.
*/

#include <iostream>
#include <stdio.h>
#include <vector>
#include <climits>

using namespace std;

struct StackNode{
  int val;
  int minsofar;
  StackNode(int data, int min): val(data), minsofar(min){}
};

vector<StackNode> Stack;

void push(int data){
  int minsofar;
  if(Stack.size() >= 1)
    minsofar = Stack[Stack.size()-1].minsofar;
  else
    minsofar = INT_MAX;
  StackNode sn(data, min(minsofar, data));
  Stack.push_back(sn);
}

StackNode pop(){
  StackNode ret = Stack[Stack.size()-1];
  Stack.pop_back();
  return ret;
}

int min(){
  StackNode ret = Stack[Stack.size()-1];
  return ret.minsofar;
}

int main(){
  for(int i = 0; i < 5; i++){
    push(i);
  }
  for(int i = 0; i < 5; i++){
    push(i-8);
  }
  StackNode temp = pop();
  cout << temp.val << endl << min();

  return 0;
}
