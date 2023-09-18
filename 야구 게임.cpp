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

using namespace std;

int main(){
  srand(time(NULL));
  int check[9] = {0, };
  int random_number;
  int count[3];
  int strike = 0, ball = 0;
  int box, n = 0;
  int user_number[3];
  vector<int> number;
  for(int i =0; i<3; i++){
    do{
      random_number = rand() % 9 + 1;
    }while(check[random_number] == 1);
    number.push_back(random_number);
  }
  cout<< "~~~야구 게임~~~" << endl;
  while(strike <3){
    strike = 0;
    ball = 0;
    int flag = 0;
    cout << "1~9 사이의 숫자 3개를 입력하시오 (이외의 숫자: 종료)" << endl;
  for(int i=0;i<3;i++){
    cin >> box;
    if(box > 9 || box < 1){
      cout << "게임을 종료하겠습니다." << endl;
      flag = 1;
      break;
    }
    user_number[i] = box;
  }
  if(flag == 1)
    break;
    int a = 0;
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      if(number[i] == user_number[j]){
        count[a] = j;
        a++;
      }
    }
  }
  for(int i = 0; i<3;i++){
    if(count[i] < 3){
      if(count[i] == i)
        strike++;
      else
        ball++;
    }
  } 
  cout << "Strike : " << strike << " Ball : " << ball << endl;
  n++;
  if(strike == 3){
    cout << n <<"번만에 정답!" << endl;
  }
  }
  }