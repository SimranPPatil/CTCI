/*
Write an algorithm such that if an element in an MxN matrix is 0, its entire row and
column is set to 0.
*/

#include <iostream>
#include <stdio.h>

#define M 4
#define N 3

using namespace std;

void makeZero(int (&arr)[M][N]){
  int row_bitmap[M] = {0};
  int col_bitmap[N] = {0};

  for(int i = 0; i < M; i++){
    for(int j = 0; j < N; j++){
      if(arr[i][j] == 0){
        row_bitmap[i] = 1;
        col_bitmap[j] = 1;
      }
    }
  }

  for(int i = 0; i < M; i++){
    if(row_bitmap[i]){
      for(int j = 0; j < N; j++){
        arr[i][j] = 0;
      }
    }
  }

  for(int i = 0; i < N; i++){
    if(col_bitmap[i]){
      for(int j = 0; j < M; j++){
        arr[j][i] = 0;
      }
    }
  }

  cout << "After: " << endl;
  for(int i = 0; i < M; i++){
    for(int j = 0; j < N; j++){
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
}

int main(){
  int arr[M][N];
  int counter = 1;
  for(int i = 0; i < M; i++){
    for(int j = 0; j < N; j++){
      if((i+j) % 5 != 0)
        arr[i][j] = counter++;
      else
        arr[i][j] = 0;
    }
  }

  cout << "Given arr: " << endl;
  for(int i = 0; i < M; i++){
    for(int j = 0; j < N; j++){
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }

  makeZero(arr);

  return 0;
}
