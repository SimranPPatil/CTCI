/*
Given an image represented by an NxN matrix, where each pixel in the image is 4
bytes, write a method to rotate the image by 90 degrees. Can you do this in place?
*/

#include <iostream>
#include <stdio.h>

#define N 5
using namespace std;

void rotate(int (&arr)[N][N] , int (&out)[N][N]){
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      out[j][N-1-i] = arr[i][j];
    }
  }
}

void rotateInPlace(int (&arr)[N][N]){
  // cyclic iterations for N/2 - 1
  int tmp, r_next, c_next, r_curr, c_curr, rounds = 0, curr;
  for(int i = 0; i <= N/2-1; i++){
    for(int j = i; j < N-1-i; j++){
      // for each have a cycle
      r_curr = i;
      c_curr = j;
      tmp = arr[i][j];
      rounds = 0;
      while(rounds < N){
        r_next = c_curr;
        c_next = N-1-r_curr;
        curr = tmp;
        tmp = arr[r_next][c_next];
        arr[r_next][c_next] = curr;
        r_curr = r_next;
        c_curr = c_next;
        rounds++;
      }
    }
  }
}

int main(){
  int arr[N][N];
  int counter = 1;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      arr[i][j] = counter++;
    }
  }

  cout << "Given arr: " << endl;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }

  int out[N][N];
  rotate(arr, out);
  rotateInPlace(arr);

  cout << "After rotateInPlace:" << endl;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
