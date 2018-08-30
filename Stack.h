#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;
template<class T>
struct StackNode{
  T data;
  StackNode(T newData): data(newData){}
};

template<class T>
class Stack{
public:
  StackNode<T> pop();
  void push(StackNode<T> newNode);
  bool isEmpty();
  int getSize();

private:
  vector< StackNode<T> > theStack;
};

template <class T>
void Stack<T>::push(StackNode<T> newNode){
  theStack.push_back(newNode);
}

template <class T>
StackNode<T> Stack<T>::pop(){
  if(!theStack.empty()){
    StackNode<T> retNode = theStack[theStack.size()-1];
    theStack.pop_back();
    return retNode;
  }
  return NULL;
}

template <class T>
bool Stack<T>::isEmpty(){
  if(theStack.empty())
    return true;
  else
    return false;
}

template <class T>
int Stack<T>::getSize(){
  return theStack.size();
}

#endif
