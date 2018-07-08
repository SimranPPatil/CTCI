/*
Assume you have a method isSubstring which checks if one word is a substring of
another. Given two strings, s1 and s2, write code to check if s2 is a rotation of s1 using
only one call to isSubstring (i.e., “waterbottle” is a rotation of “erbottlewat”).
*/

#include <iostream>
#include <stdio.h>

using namespace std;

bool isSubstring(string str1, string str2){
  // checks is str2 is a substring of str1
  if(str2.length() > str1.length())
    return isSubstring(str2, str1);

  for(int i = 0; i < str1.length(); ){
    if(str1[i] == str2[0]){
      int curr = i;
      int j = 0;
      while(str1[i] == str2[j]){
        i++;
        j++;
      }
      if(j == str2.length())
        return true;
      else{
        i = curr+1;
        j = 0;
      }
    }
    else
      i++;
  }
  return false;
}

bool isRotated(string str1, string str2){
  if(str1.length() != str2.length())
    return false;
  int i = 0, j = 0;
  string str = str1 + str1;
  return isSubstring(str, str2);
}

int main(){
  string str1 = "erbottle";
  string str2 = "waterbottle";
  cout << " val is \n" << isRotated(str1, str2) << endl;
  return 0;
}
