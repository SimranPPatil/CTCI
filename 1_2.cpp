/*
Write code to reverse a C-Style String. (C-String means that “abcd” is represented as
five characters, including the null character.)
*/

#include <iostream>
#include <stdio.h>
#include <cstring>
#include <stack>
#include <string>


using namespace std;

char* reverseCStringStack(char* str){
  stack<char> rev;
  int i;
  for(i = 0; str[i] != '\0'; i++){
    rev.push(str[i]);
  }
  char* out = new char[i+1];
  i = 0;
  while(!rev.empty()){
    out[i] = rev.top();
    rev.pop();
    i++;
  }
  out[i] = '\0';
  return out;
}

void reverseCStringInPlace(char* str){
  char tmp;
  char* end = str;
  if(str){
    while(*end)
      end++;
    end--;
    while(str < end){
      tmp = *end;
      *end-- = *str;
      *str++ = tmp;
    }
  }
}

int main(){
  string str = "abcd";
  char * cstr = new char [str.length()+1];
  std::strcpy (cstr, str.c_str());
  //char* s = (char*) "abcd\0"; // caused bus error when passed to function
  reverseCStringInPlace(cstr);
  for(int i = 0; cstr[i] != '\0'; i++)
    cout << cstr[i];
  free(cstr);
  return 0;
}
