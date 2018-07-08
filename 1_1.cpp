/*
Implement an algorithm to determine if a string has all unique characters. -->allUniqueFirst
What if you can not use additional data structures? --> allUniqueSecond
*/

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

bool allUniqueFirst(string& str){
  vector <int> arr (256, -1);
  for(int i = 0; i < str.length(); i++){
    if(arr[str[i]] == -1)
      arr[str[i]] = i;
    else
      return false;
  }
  return true;
}

bool allUniqueSecond(string& str){
  // assumes only lower case alphabet so that int would suffice, uses bit shifts
  int checker = 0;
  for(int i = 0; i < str.length(); i++){
    int val = str[i] - 'a'; // gives ascii value
    // set bit for that character if first occurrence
    if((checker & (1<<val)) > 0){
      return false;
    }
    else
      checker |= (1<<val);
  }
  return true;
}

int main(){
  string str = "abc";
  cout << "First: " << allUniqueFirst(str) << " for " << str << endl;
  cout << "Second: " << allUniqueSecond(str) << " for " << str << endl;
  return 0;
}
