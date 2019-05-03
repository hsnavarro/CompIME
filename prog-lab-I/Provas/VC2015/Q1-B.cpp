#include <bits/stdc++.h>
using namespace std;

// Por referência
void func1 (int &a){
  a += 10;
}

// Por ponteiro
void func2 (int *b){
  *b += 20;
}

int main(){
  int a = 0;
  int *b = &a;
  func1(a);
  cout << a << endl;
  func2(b);
  cout << a << endl;
}

