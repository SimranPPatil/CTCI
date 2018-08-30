/*
Write a method to replace all spaces in a string with ‘%20’.
*/

// questions: pass by refernce, value on stack, return by value
// free vs delete

#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

string replaceSpacesLOL(string& str){
  // don't do this :P
  for(int i = 0; i < str.length(); i++){
    if(str[i] == ' ')
      str.replace(i,1,"%20");
  }
  return str;
}


int getLength(char* str, int length){
  int counter = 0;
  for(int i = 0; i < length; i++){
    if(str[i] == ' ')
      counter++;
  }
  return counter;
}

void replaceSpaces(char* str, int length, char* newstr){
  // can be done with a copy but avoid that
  int j = 0;
  for(int i = 0; i < length; i++){
    if(str[i] == ' '){
      newstr[j] = '%';
      newstr[j+1] = '2';
      newstr[j+2] = '0';
      j+=3;
    }
    else{
      newstr[j] = str[i];
      j++;
    }
  }
}

int main(){
  string str1 = "apple a day  ";
  char* str = new char[str1.length()+1];
  strcpy(str,str1.c_str());
  int counter = getLength(str,str1.length()+1);
  char* newstr = new char[(str1.length()+1)+2*counter];
  replaceSpaces(str, str1.length()+1, newstr);
  for(int i = 0; newstr[i] != '\0'; i++){
    cout << newstr[i];
  }
  delete[] str;
  delete[] newstr;
  return 0;
}
