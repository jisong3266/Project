#pragma once
#include "Character.h"
#include "Monster.h"
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Weapon : public Character, public Monster {
public:
  Monster m;
  int power, number;
  virtual void attack() {}
  virtual void gain() {}
  void Level_up() {
    cout << endl << "👏🏻!!!LEVEL UP!!!👏🏻" << endl <<"게임 캐릭터의 HP + 10, 무기의 POWER + 5가 되었습니다!"<< endl;
    number++;
    Character::hp += 10;
    power += 5;
  }
};
class Gun : public Weapon {
public:
  int power = 10;
  int number = 0;
  virtual void attack() {
    cout << "\033[38;5;21m!!총쏘기!!" << endl;
    number--;
  }
  virtual void Show_info() { cout << "공격 가능 횟수 : " << number << endl; }
  virtual void gain() { number++; }
  int get() { return number; }
};
class Sword : public Weapon {
public:
  int power = 5;
  int number = 0;
  virtual void attack() {
    cout << "\033[38;5;21m!!찌르기!!" << endl;
    number--;
    /*m.hp = m.m_get() - power;
    if(m.hp <= 0){
      cout << "몬스터가 죽었습니다!\033[38;5;15m" << endl;
      Level_up();
    } 
    else{
      Show_info();
      cout << "몬스터의 hp : " << m.m_get() << "\033[38;5;15m"<< endl;  
    }*/
  }
  virtual void gain() { number++; }
  virtual void Show_info() { cout << "공격 가능 횟수 : " << number << endl; }
  int get() { return number; }
};