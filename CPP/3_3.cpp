/*
Imagine a (literal) stack of plates. If the stack gets too high, it might topple. Therefore,
in real life, we would likely start a new stack when the previous stack exceeds
some threshold. Implement a data structure SetOfStacks that mimics this. SetOfStacks
should be composed of several stacks, and should create a new stack once
the previous one exceeds capacity. SetOfStacks.push() and SetOfStacks.pop() should
behave identically to a single stack (that is, pop() should return the same values as it
would if there were just a single stack).
FOLLOW UP
Implement a function popAt(int index) which performs a pop operation on a specific
sub-stack.
*/


#include <iostream>
#include <stdio.h>
#include <vector>
#include "Stack.h"

#define THRESHOLD 100

using namespace std;

template <class T>
class SetOfStacks{
public:
  SetOfStacks();
  void push(StackNode<T> newNode);
  StackNode<T> pop();
  StackNode<T> popAt(int index);
private:
  vector< Stack<T> > theSet;
};

template <class T>
void SetOfStacks::push(StackNode<T> newNode){

}


int main(){
  Stack<int> myStack;
  myStack.push(9);
  StackNode<int> node = myStack.pop();
  cout << node.data << endl;

  myStack.push(0);
  myStack.push(22);
  node = myStack.pop();
  cout << node.data << endl;

  cout << myStack.isEmpty() << endl;
  cout << myStack.getSize() << endl;

  return 0;
}
