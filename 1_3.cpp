/*
Design an algorithm and write code to remove the duplicate characters in a string
without using any additional buffer. NOTE: One or two additional variables are fine.
An extra copy of the array is not.
*/

// can also be done with const array of 256 for ascii
// int will work for lowercase only

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

void removeDup(string& str){
  int checker = 0;
  int val;
  for(int i = 0; i < str.length(); i++){
    val = str[i] - 'a';
    if((checker & (1<<val))){
      str.erase(i,1);
      i--;
    }
    else
      checker |= (1<<val);
  }
}

int main(){
  string str = "aabbababa";
  removeDup(str);
  cout << str << endl;
  return 0;
}
