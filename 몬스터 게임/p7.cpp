#pragma once
#include "Character.h"
#include "Monster.h"
#include "Weapon.h"
#include <cctype>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
// 3번이기면 스페셜 캐릭터 + 몬스터 나옴
//맨 처음에는 캐릭터 먼저 만들고, 골라야 함!
//맨손으로 때리기
int main() {
  srand(time(NULL));
  int num, count = 0, flag = 0, character_num, game_level = 1,
           weapon_number = 0, random_number, box, round = 1;
  string name;
  Character ch;
  Gun g;
  Sword s;
  Weapon w;
  Character *character_bag[100] = {
      0,
  };
  cout << "~~~게임시작~~~" << endl;
  Monster* m1 = new Monster(game_level);
  box = game_level;
  cout << "GAME LEVEL : " << game_level << endl;
  m1->Show_info();
  while (1) {
    int game_count = 0;
    if (box != game_level) {
      m1 = new Monster(game_level);
      box = game_level;
      cout << "GAME LEVEL : " << game_level << endl;
      m1->Show_info();
    }
    box = game_level;
    cout << endl << "----------------------------------" << endl;
    cout << "숫자를 입력하세요( 0:캐릭터 고르기, 1:공격하기, 2:무기줍기, 3: "
            "캐릭터 만들기, 4 : 종료)"
         << endl;
    cin >> num;
    switch (num) {
    case 0:
      if (count == 0) {
        cout << "캐릭터가 없습니다. 캐릭터를 만들어주세요\n";
        break;
      } else {
        for (int i = 0; i < count; i++) {
          cout << i << " : ";
          character_bag[i]->Show_info();
        }
        cout << "캐릭터 번호를 입력하세요 : ";
        cin >> character_num;
      }
      //캐릭터 목록 나열하기
      break;
    case 1:
      if (character_bag[character_num]->wpn[0] == "N/A" || (g.get() == 0 && s.get() == 0)) {
        cout << "사용 가능한 무기가 없습니다. 무기를 주워주세요" << endl;
        break;
      } 
      else {
        for (int i = 0; i < character_bag[character_num]->wpn.size(); i++) {
          cout << i << " : " << character_bag[character_num]->wpn[i] << endl;
        }
        cout << "사용할 무기 번호를 입력하세요 : ";
        cin >> weapon_number;
        if (character_bag[character_num]->wpn[weapon_number] == "총") {
          if(g.get() == 0){
            cout << "사용 가능한 총이 없습니다. 다른 무기 번호를 입력하세요" << endl;
          }
          else {
            g.attack();
            m1->hp -= g.power;
            if(m1->hp <= 0){
               cout << "몬스터가 죽었습니다!\033[38;5;15m" << endl;
               w.Level_up();
               character_bag[character_num] -> Level_up();
               round ++;
               game_count = 0;
            }
            else{
              g.Show_info();
              cout << "몬스터의 hp : " << m1->m_get() << "\033[38;5;15m"<< endl;
            }
            if (g.get() == 0)
             cout << "총을 모두 사용했습니다!" << endl;
         }
        }
        else {
          if(s.get() == 0){
            cout << "사용 가능한 검이 없습니다. 다른 무기 번호를 입력하세요" << endl;
          }
          else{
            s.attack();
            m1->hp -= s.power;
            if(m1->hp <= 0){
               cout << "몬스터가 죽었습니다!\033[38;5;15m" << endl;
               w.Level_up();
               character_bag[character_num] -> Level_up();
               game_count = 0;
               round++;
            }
            else{
              g.Show_info();
              cout << "몬스터의 hp : " << m1->m_get() << "\033[38;5;15m"<< endl;
            }
          if (s.get() == 0)
            cout << "검을 모두 사용했습니다!" << endl;
        }
        }
        game_count = 1;
      }
      //어떤 무기 사용할지 선택
      //공격 후 남은 공격 횟수 출력
      break;
    case 2:
      game_count = 1;
      random_number = rand() % 2 + 1;
      if (random_number == 1) {
        if (character_bag[character_num]->wpn[0] == "검") {
          if (character_bag[character_num]->wpn.size() < 2) {
            character_bag[character_num]->wpn.push_back("총");
          }
        } 
          else if (character_bag[character_num]->wpn[0] != "총")
            character_bag[character_num]->wpn[0] = "총";
        cout << "총을 주웠습니다!! ";
        g.gain();
        g.Show_info();
      } 
      else if (random_number == 2) {
        if (character_bag[character_num]->wpn[0] == "총"){
          if (character_bag[character_num]->wpn.size() < 2) {
            character_bag[character_num]->wpn.push_back("검");
          }
        } 
          else if (character_bag[character_num]->wpn[0] != "검")
             character_bag[character_num]->wpn[0] = "검";
        cout << "검을 주웠습니다!! ";
        s.gain();
        s.Show_info();
      }
      //같은 무기 주으면 공격 횟수++
      break;
    case 3: {
      cout << "이름을 입력하세요 : ";
      cin >> name;
      Character *ch1 = new Character(name);
      character_bag[count] = ch1;
      count++;
      cout << "캐릭터를 만들었습니다!" << endl;
      break;
    }
    case 4:
      flag = 1;
      break;
    }
    if (flag == 1)
      break;
    if (round != box)
      game_level++;
    else if (game_count == 1) {
      m1->m_attack();
      character_bag[character_num]->hp -= m1->attack_power;
      if(character_bag[character_num]->hp < 0){
        cout << "GAME OVER!" << endl;
        character_bag[character_num]->hp = 
      }
      cout << " 남은 HP : " << character_bag[character_num]->hp <<"\033[38;5;15m";
    }
  }
}