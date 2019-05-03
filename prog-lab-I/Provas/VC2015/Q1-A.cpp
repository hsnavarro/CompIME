#include <bits/stdc++.h>
using namespace std;

// Resolver ambiguidade classe base e derivada

class A{
  public:
    int a;
};

class B : public A{
  public:
    int a = 2;
    void changeA (){
      A::a = 10;
    }
};

int main(){
  B teste;
  cout << teste.a << endl;
  teste.changeA();
  cout << teste.A::a << endl;
}
