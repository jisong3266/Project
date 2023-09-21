#pragma once
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

class Character {
public:
  string name;
  int hp;
  int level;
  vector<string> wpn;
  Character(){};
  Character(string name) {
    this->name = name;
    level = 0;
    hp = 20;
    wpn.push_back("N/A");
  };
  virtual void Show_info() {
    cout << "NAME = " << name;
    cout << " LEVEL = " << level;
    cout << " HP = " << hp;
    cout << " WEAPONS = ";
    for (int i = 0; i < wpn.size(); i++) {
      cout << wpn[i] << endl;
    }
  }
  virtual void Level_up(){
    level++;
    hp *= 1.5;
  }
};
