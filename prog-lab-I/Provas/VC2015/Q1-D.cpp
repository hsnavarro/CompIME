#include <bits/stdc++.h>
using namespace std;

// Redefinição
class Princ{
  public:
    int a = 0;
    void soma(){
      a += 10;
    }
};

class Sub: public Princ{
  public:
    int b = 0;
    void soma(){
      b += 20;
    }
};

// Overload
class Arit{
  public:
    int soma(int a){
      return a + 10;
    }
    int soma(int a, int b){
      return a + b;
    }
};

int main(){
  Sub var;
  var.soma();
  cout << var.b << endl; // var.b = 20;
  var.Princ::soma();
  cout << var.a << endl; // var.a = 10;

  Arit calc;
  cout << calc.soma(5) << endl; // 15
  cout << calc.soma(2, 3) << endl; // 5
}
