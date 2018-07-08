/*
Describe how you could use a single arr to implement three stacks.
*/

#include <iostream>
#include <stdio.h>

using namespace std;

#define STACKSIZE 30
int arr[3*STACKSIZE];
int stacktop[3] = {0, STACKSIZE/3, STACKSIZE/3*2};

struct StackNode{
  int val;
  int prev;
  StackNode(int data, int p){
    val = data;
    prev = p;
  }
};

bool push(int val, int stacknum){
  int index = stacktop[stacknum-1];
  if(index >= STACKSIZE/3*stacknum)
    return false;
  arr[index] = val;
  stacktop[stacknum-1] = index+1;

  return true;
}

bool pop(int stacknum){
  int index = stacktop[stacknum-1]-1;
  if(index < STACKSIZE/3*(stacknum-1))
    return false;
  stacktop[stacknum-1] = index;
  return true;
}

int peek(int stacknum){
  int index = stacktop[stacknum-1]-1;
  if(index < 0)
    return -1;
  return arr[index];
}

bool isEmpty(int stacknum){
  if(stacktop[stacknum-1] == STACKSIZE/3*(stacknum-1))
    return true;
  return false;
}

int main(){
  for(int i = 0; i < 5; i++)
    push(i,1);

  cout << peek(2) << endl;
  cout << peek(1) << endl;
  cout << isEmpty(1) << endl << isEmpty(3) << endl;
  cout << pop(1) << endl;
  cout << peek(1) << endl;

  return 0;
}
