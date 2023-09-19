#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include<iomanip> 
using namespace std;
void diagonal(int box, int m){
  box--;
  m++;
}
int main(){
  int n;
  int i = 1;
  cout << "마방진의 행 혹은 열의 수를 자연수로 입력하세요 : ";
  cin >> n;
  int **magic_square = new int *[n];
  for(int i=0;i<n;i++){
    magic_square[i] = new int[n];
  }
  for(int i=0;i<n;i++){
    for(int j =0;j<n;j++){
      magic_square[i][j] = 0;
    }
  }
  if(n % 2 == 1){
    int box = n-1;
    int m = n /2;
    magic_square[0][m] = i;
    i++;
    m++;
    while(i <= n * n){
      magic_square[box][m] = i;
      i++;
      box--;
      m++;
      if(box >= 0 && m < n && magic_square[box][m] != 0){
        box += 2;
        m--;
        continue;
      }
      if(box < 0){
        if(m == n){
          box += 2;
          m--;
        }
        else{
          box = n-1;
        }
       continue;
      }
    if(m == n){
      m = 0;
      continue;
    }
    }
    for(int i=0;i<n;i++){
      for(int j =0;j<n;j++){
        cout << setw(3) << magic_square[i][j];
    }
      cout << endl;
  }
  }
    for (int i = 0; i < n; i++){
        delete[] magic_square[i];
    }
    delete[] magic_square;
}
