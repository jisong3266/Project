#include "Character.h"
#include "Monster.h"
#include "Weapon.h"
#include <algorithm>
#include <cctype>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int ChooseCharacter(Character *character_bag[], int &count) {
  string name;
  cout << "캐릭터의 이름을 입력하세요 : ";
  cin >> name;
  Character *ch1 = new Character(name);
  character_bag[count] = ch1;
  count++;
  cout << name << "캐릭터를 만들었습니다!" << endl;
  return count - 1;
}

void ShowCharacterList(Character *character_bag[], int count) {
  cout << "-----캐릭터 목록-----" << endl;
  for (int i = 0; i < count; i++) {
    cout << i << " : ";
    character_bag[i]->Show_info();
  }
}

int ChooseWeapon(Character *character_bag[], int character_num, int round,
                 int &game_count, Weapon &w, Gun &g, Sword &s, Monster *m1) {
  int weapon_number;
  if (character_bag[character_num]->wpn[0] == "N/A" ||
      (g.get() == 0 && s.get() == 0)) {
    cout << "사용 가능한 무기가 없습니다. 무기를 주워주세요" << endl;
    return -1;
  } else {
    for (int i = 0; i < character_bag[character_num]->wpn.size(); i++) {
      cout << i << " : " << character_bag[character_num]->wpn[i]
           << " 사용 가능 횟수 : ";
      if (character_bag[character_num]->wpn[i] == "총")
        cout << g.get() << endl;
      else if (character_bag[character_num]->wpn[i] == "검")
        cout << s.get() << endl;
    }
    cout << "사용할 무기 번호를 입력하세요 : ";
    cin >> weapon_number;
    if (character_bag[character_num]->wpn[weapon_number] == "총") {
      if (g.get() == 0) {
        cout << "사용 가능한 총이 없습니다. 다른 무기 번호를 입력하세요"
             << endl;
        return -1;
      } else {
        g.attack();
        m1->hp -= g.power;
        if (m1->hp <= 0) {
          cout << "몬스터가 죽었습니다!\033[38;5;15m" << endl;
          w.Level_up();
          character_bag[character_num]->Level_up();
          game_count = 0;
          round++;
          return -2;
        } else {
          cout << "몬스터의 남은 HP : " << m1->hp << endl;
          return 0;
        }
      }
    } else {
      if (s.get() == 0) {
        cout << "사용 가능한 검이 없습니다. 다른 무기 번호를 입력하세요"
             << endl;
        return -1;
      } else {
        s.attack();
        m1->hp -= s.power;
        if (m1->hp <= 0) {
          cout << "몬스터가 죽었습니다!\033[38;5;15m" << endl;
          w.Level_up();
          game_count = 0;
          round++;
          return -2;
        } else {
          cout << "몬스터의 남은 HP : " << m1->hp << endl;
          return 0;
        }
      }
    }
  }
}

void GainWeapon(Character *character_bag[], int character_num, Gun &g,
                Sword &s) {
  int random_number = rand() % 2 + 1;
  if (random_number == 1) {
    if (character_bag[character_num]->wpn[0] == "검") {
      if (character_bag[character_num]->wpn.size() < 2) {
        character_bag[character_num]->wpn.push_back("총");
      }
    } else if (character_bag[character_num]->wpn[0] != "총") {
      character_bag[character_num]->wpn[0] = "총";
    }
    cout << "총을 주웠습니다!!" << endl;
    g.gain();
  } else if (random_number == 2) {
    if (character_bag[character_num]->wpn[0] == "총") {
      if (character_bag[character_num]->wpn.size() < 2) {
        character_bag[character_num]->wpn.push_back("검");
      }
    } else if (character_bag[character_num]->wpn[0] != "검") {
      character_bag[character_num]->wpn[0] = "검";
    }
    cout << "검을 주웠습니다!!" << endl;
    s.gain();
  }
}

int main() {
  srand(time(NULL));
  int num, count = 0, flag = 0, character_num, character_num2,
           weapon_number = 0, random_number, box, round = 1, game_type,
           game_level = 1;
  string name;
  Character ch;
  Gun g;
  Sword s;
  Weapon w;
  Character *character_bag[100] = {0};

  cout << "~~~게임시작~~~" << endl;
  cout << "게임 유형을 선택하세요 : (0: 1P, 1: 2P)";
  cin >> game_type;

  switch (game_type) {
  case 0: {
    game_level = 1;
    cout << "1P를 선택했습니다" << endl;
    if (count == 0) {
      character_num = ChooseCharacter(character_bag, count);
    }
    Monster *m1 = new Monster(game_level);
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
      cout << "숫자를 입력하세요(0:캐릭터 고르기, 1:캐릭터 만들기, 2:공격하기, "
              "3:무기줍기, 4:종료)"
           << endl;
      cin >> num;

      switch (num) {
      case 1: {
        character_num = ChooseCharacter(character_bag, count);
        break;
      }
      case 0: {
        ShowCharacterList(character_bag, count);
        cout << "캐릭터 번호를 입력하세요 : ";
        cin >> character_num;
        break;
      }
      case 2: {
        int weapon_choice = ChooseWeapon(character_bag, character_num,
                                         game_count, round, w, g, s, m1);
        if (weapon_choice == -1) {
          continue;
        }
        if (weapon_choice == -2) {
          game_level++;
          character_bag[character_num]->Level_up();
          continue;
        }
        if (weapon_choice == 0) {
          g.Show_info();
        } else {
          s.Show_info();
        }
        game_count = 1;
        break;
      }
      case 3: {
        game_count = 1;
        GainWeapon(character_bag, character_num, g, s);
        break;
      }
      case 4: {
        flag = 1;
        break;
      }
      }
      if (flag == 1)
        break;
      if (game_level == box && game_count == 1) {
        m1->m_attack();
        character_bag[character_num]->hp -= m1->attack_power;
        if (character_bag[character_num]->hp < 0) {
          cout << "GAME OVER!\033[38;5;15m" << endl;
          character_bag[character_num]->hp = 20;
          g.power = 10;
          s.power = 5;
        } else
          cout << " 남은 HP : " << character_bag[character_num]->hp
               << "\033[38;5;15m";
      }
    }
    break;
  }
  case 1: {
    count = 0, flag = 0, weapon_number = 0, round = 1, game_level = 1;
    count = 0, flag = 0, game_level = 1, weapon_number = 0, round = 1;
    int character_num2[2];
    cout << "2P를 선택했습니다" << endl;
    if (count == 0) {
      cout << "Player1의 이름을 입력하세요 : ";
      cin >> name;
      Character *ch1 = new Character(name, 1);
      character_bag[count] = ch1;
      character_num2[0] = count;
      count++;
      cout << name << "캐릭터를 만들었습니다! 랜덤 HP : "
           << character_bag[character_num2[0]]->hp << endl;
      cout << "Player2의 이름을 입력하세요 : ";
      cin >> name;
      Character *ch2 = new Character(name, 1);
      character_bag[count] = ch2;
      character_num2[1] = count;
      count++;
      cout << name << "캐릭터를 만들었습니다! 랜덤 HP : "
           << character_bag[character_num2[1]]->hp << endl;
    }
    Monster *m1 = new Monster(game_level);
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
        cout << "Player1의 HP : " << character_bag[character_num2[0]]->hp
             << endl;
        cout << "Player2의 HP : " << character_bag[character_num2[1]]->hp
             << endl;
      }
      box = game_level;
      for (int i = 0; i < 2; i++) {
        if (box != game_level) {
          m1 = new Monster(game_level);
          box = game_level;
          cout << "GAME LEVEL : " << game_level << endl;
          m1->Show_info();
        }
        if (i == 0)
          cout << "\033[38;5;219mPlayer1\033[38;5;15m" << endl;
        else
          cout << "\033[38;5;214mPlayer2\033[38;5;15m" << endl;
        box = game_level;
        cout << endl << "----------------------------------" << endl;
        cout << "숫자를 입력하세요(0:캐릭터 고르기, 1:캐릭터 만들기, "
                "2:공격하기, 3:무기줍기, 4:종료)"
             << endl;
        cin >> num;
        switch (num) {
        case 1: {
          character_num2[i] = ChooseCharacter(character_bag, count);
          break;
        }
        case 0: {
          ShowCharacterList(character_bag, count);
          cout << "Player" << i + 1 << "의 캐릭터 번호를 입력하세요 : ";
          cin >> character_num2[i];
          break;
        }
        case 2: {
          int weapon_choice = ChooseWeapon(character_bag, character_num2[i],
                                           game_count, round, w, g, s, m1);
          if (weapon_choice == -1) {
            i--;
            continue;
          }
          if (weapon_choice == -2) {
            game_level++;
            character_bag[character_num2[0]]->Level_up();
            character_bag[character_num2[1]]->Level_up();
            continue;
          }
          game_count = 1;
          break;
        }
        case 3: {
          game_count = 1;
          GainWeapon(character_bag, character_num2[i], g, s);
          break;
        }
        case 4: {
          flag = 1;
          break;
        }
        }
        if (flag == 1)
          break;
      }
      if (box == game_level && game_count == 1) {
        for (int i = 0; i < 2; i++) {
          m1->m_attack();
          character_bag[character_num2[i]]->hp -= m1->attack_power;
          if (character_bag[character_num2[i]]->hp <= 0) {
            cout << "Player" << i + 1 << "이 죽었습니다!" << endl;
            character_bag[character_num2[i]]->hp = 0;
          }
          cout << "Player" << i + 1
               << "의 남은 HP : " << character_bag[character_num2[i]]->hp
               << "\033[38;5;15m" << endl;
        }
        if (character_bag[character_num2[0]]->hp <= 0 &&
            character_bag[character_num2[1]]->hp <= 0) {
          cout << "GAME OVER!!\033[38;5;15m" << endl;
          g.power = 10;
          s.power = 5;
        }
      }
    }
    break;
  }
    for (int i = 0; i < count; i++) {
      delete character_bag[i];
    }

    return 0;
  }
}
