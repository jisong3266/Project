#pragma once
#include "Character.h"
#include "Monster.h"
#include <algorithm>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Weapon : public Character, public Monster {
public:
  Monster m;
  int power, number;
  virtual void attack() {}
  virtual void gain() {}
  void Level_up() {
    cout << endl
         << "👏!!!LEVEL UP!!! HP + 10, 무기POWER + 5가 "
            "되었습니다👏"<< endl;
    number++;
    Character::hp += 10;
  }
};
class Gun : public Weapon {
public:
  Gun() {
    power = 10;
    number = 0;
  };
  virtual void attack() {
    cout << "\033[38;5;21m!!총쏘기!!" << endl;
    number--;
  }
  virtual void Show_info() {
    if (number == 0) {
      cout << "총을 모두 사용했습니다 !" << endl;
    }
    else
      cout << "공격 가능 횟수 : " << number << endl;
  }
  virtual void gain() { number++; }
  int get() { return number; }
};
class Sword : public Weapon {
public:
  Sword() {
    power = 5;
    number = 0;
  }
  virtual void attack() {
    cout << "\033[38;5;21m!!찌르기!!" << endl;
    number--;
  }
  virtual void gain() { number++; }
  virtual void Show_info() {
    if (number == 0) {
      cout << "검을 모두 사용했습니다 !" << endl;
    }
    cout << "공격 가능 횟수 : " << number << endl;
  }
  int get() { return number; }
};