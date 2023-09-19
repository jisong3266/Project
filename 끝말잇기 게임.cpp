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
  string word;
  vector<string> word_box;
  char first, last;
  cout << "~~~끝말잇기(제한시간 30초)~~~\n";
  cout << "첫 단어를 입력하세요 : ";
  clock_t startTime = clock();
  cin >> word;
  last = word[word.size()-1];
  word_box.push_back(word);
  cout << word << endl;
  double sum = 0;
  while(1){
    clock_t endTime = clock();
    sum = double(endTime - startTime) / 100;
    if( sum > 30){
      cout << "타임 오버 !!\n 게임 종료!!";
      cout << "총 입력한 단어 개수 : " << word_box.size()-1;
      break;
    }
    cout << "다음 단어를 입력하세요 : ";
    cin >> word;
    first = word[0];
    if(find(word_box.begin(),word_box.end(),word) != word_box.end()){
      cout << "중복된 단어입니다.\n";
      continue;
  }
    else if(last != first){
      cout << "잘못된 입력입니다.\n";
      continue;
    }
    last = word[word.size()-1];
    word_box.push_back(word);
    for(int i =0; i<word_box.size()-1;i++){
      cout << word_box[i] << "->";
      }
      cout << word_box[word_box.size()-1] << endl;
  }
    }
}
