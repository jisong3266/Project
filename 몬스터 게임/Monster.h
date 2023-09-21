#pragma once
#include <algorithm>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Monster {
public:
  int hp;
  int attack_power = 3;
  int level;
  Monster(){};
  Monster(int level) {
    this->level = level;
    hp = level * 15;
    attack_power = 3 * level;
  }
  virtual void Show_info() {
    cout << "<MONSTER ";
    cout << " LEVEL = " << level;
    cout << " HP = " << hp;
    cout << " Attack power = " << attack_power << ">" << endl;
  }
  void m_attack() { cout << "\033[38;5;196m!!몬스터에게 공격을 당했습니다!!"; }
  int m_get() { return hp; }
};