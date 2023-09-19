#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Calculator {
public:
  static double sum; 
  virtual void Add1(double a, double b){};
  virtual void Sub1(double a, double b){};
  virtual void Mul1(double a, double b){};
  virtual void Div1(double a, double b){};
};
double Calculator::sum = 0;

class Add : public Calculator {
public:
  virtual void Add1(double a, double b) { sum = a + b; };
};
class Sub : public Calculator {
public:
  virtual void Sub1(double a, double b) { sum = a - b; }
};
class Mul : public Calculator {
public:
  virtual void Mul1(double a, double b) { sum = a * b; }
};
class Div : public Calculator {
public:
  virtual void Div1(double a, double b) { sum = a / b; }
};
void oprtr(char op, double n1, double n2){
    switch (op) {
  case '+': {
    Calculator *add = new Add();
    add->Add1(n1, n2);
    break;
  }
  case '-': {
    Calculator *sub = new Sub();
    sub->Sub1(n1, n2);
    break;
  }
  case '*': {
    Calculator *mul = new Mul;
    mul->Mul1(n1, n2);
    break;
  }
  case '/': {
    Calculator *div = new Div;
    div->Div1(n1, n2);
    break;
  }
  }
  };
void print(double total){
  string input;
  cout << "------------------------------------" << endl;
  cout << "결과 : " << total << endl;
  cout << "연산을 계속 진행하시겠습니까? (Y: 계속, AC: 초기화, EXIT: 종료)";
};
int main() {
  double n1, n2;
  char op;
  Calculator c;
  string input;
  cout << "숫자를 입력해주세요 : ";
  cin >> n1;
  cout << "연산자를 입력해주세요 : ";
  cin >> op;
  cout << "숫자를 입력해주세요 : ";
  cin >> n2;
  oprtr(op, n1, n2);
  print(c.sum);
  while (1) {
    cin >> input;
    if(input == "Y"){
      cout << "연산자를 입력하세요 : ";
      cin >> op;
      cout << "숫자를 입력해주세요 : ";
      cin >> n2;
      oprtr(op, c.sum, n2);
      print(c.sum);
    }
    if(input == "AC"){
      c.sum = 0;
      cout << "숫자를 입력해주세요 : ";
      cin >> n1;
      cout << "연산자를 입력해주세요 : ";
      cin >> op;
      cout << "숫자를 입력해주세요 : ";
      cin >> n2;
      oprtr(op, n1, n2);
      print(c.sum);
    }
    if(input == "EXIT"){
      cout << "종료";
      break;
    }
  }
}
