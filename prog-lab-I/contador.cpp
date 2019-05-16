#include <bits/stdc++.h>
using namespace std;

class Contador {
  static int cnt;
 public:
  static int getCnt() { return cnt; }
  Contador(){ cnt++; }  
  ~Contador(){ cnt--; }
};

int Contador::cnt = 0;

int main(){
 Contador A, B, C;
 cout << Contador::getCnt() << endl;
}
