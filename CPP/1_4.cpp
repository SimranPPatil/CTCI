/*
Write a method to decide if two strings are anagrams or not
*/

#include <iostream>
#include <stdio.h>
#include <string>
#include <map>

using namespace std;

bool checkAnagram(string str1, string str2){
  if(str1.length() != str2.length())
    return false;

  map <char, int> counter;
  for(int i = 0; i < str1.length(); i++){
    if(counter.find(str1[i]) == counter.end())
      counter[str1[i]] = 1;
    else
      counter[str1[i]]++;
  }

  for(int i = 0; i < str2.length(); i++){
    if(counter.find(str2[i]) != counter.end()){
      counter[str2[i]]--;
      if(counter[str2[i]] == 0)
        counter.erase(str2[i]);
    }
  }

  if(counter.empty())
    return true;

  return false;
}

int main(){
  string str1 = "aphple";
  string str2 = "ppleaf";
  cout << checkAnagram(str1, str2) << " for strings " << str1 << " & " << str2 <<endl;
  return 0;
}
