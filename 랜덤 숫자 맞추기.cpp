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
  int check[25] = {0, };
  int random_number;
  int count = 0;
  int box;
  vector<int> user_number;
  vector<int> number;
  for(int i =0; i<6; i++){
    do{
      random_number = rand() % 25 + 1;
    }while(check[random_number] == 1);
    number.push_back(random_number);
  }
  cout << "숫자는 1 ~ 25까지의 숫자만 입력할 수 있습니다." << endl;
  cout << "1번째 숫자를 입력하세요 : ";
  cin >> box;
  user_number.push_back(box);
  for(int i=1; i<6; i++){
    cout << i+1 << "번째 숫자를 입력하세요 : ";
    cin >> box;
    if(find(user_number.begin(), user_number.end(),box) != user_number.end()){
      cout << "이미 입력된 숫자입니다. 다시 입력해주세요" << endl;
      i--;
    }
    else if(box > 25 || box < 1){
      cout << "잘못된 숫자입니다. 다시 입력해주세요" << endl;
      i--;
    }
    else 
      user_number.push_back(box);
  }
  cout << "당첨번호 공개!\n";
  for(int i=0; i< 6;i++){
    if(find(user_number.begin(), user_number.end(), number[i]) != user_number.end()){
        count ++;
      }
    cout << number[i] << " ";
    }
  cout << "\n";
  cout << "1~7등까지 결과가 나올 수 있습니다." << endl;
  switch(count){
    case 0:
      cout << "결과 : 7등입니다!" << endl;
      break;
    case 1:
      cout << "결과 : 6등입니다!" << endl;
      break;
    case 2:
      cout << "결과 : 5등입니다!" << endl;
      break;
    case 3:
      cout << "결과 : 4등입니다!" << endl;
      break;
    case 4:
      cout << "결과 : 3등입니다!" << endl;
      break;
    case 5:
      cout << "결과 : 2등입니다!" << endl;
      break;
    case 6:
      cout << "결과 : 1등입니다!" << endl;
      break;
  }
}
