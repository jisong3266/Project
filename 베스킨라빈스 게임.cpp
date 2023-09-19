int i;

int num(int n) {
  for (int k = 0; k < n; k++) {
    cout << i << endl;
    if (i == 31) {
      i++;
      break;
    }
    i++;
  }
  return i;
}
int main() {
  srand(time(NULL));
  int user_num, pc_num;
  i = 1;
  cout << "~~~베스킨라빈스 31~~~\n";
  while (1) {
    while (1) {
      cout << "개수를 입력하세요: ";
      cin >> user_num;
      if (user_num < 1 || user_num > 3) {
        cout << "1~3 사이의 수를 입력하세요\n";
      } else {
        break;
      }
    }
    cout << "사용자가 부른 숫자!!" << endl;
    num(user_num);
    if (i == 32) {
      cout << "게임 종료! 컴퓨터의 승리입니다.";
      break;
    }
    cout << "컴퓨터가 부른 숫자!!" << endl;
    pc_num = rand() % 3 + 1;
    num(pc_num);
    if (i == 32) {
      cout << "게임 종료! 사용자의 승리입니다.";
      break;
    }
  }
}
