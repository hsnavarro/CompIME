#include <bits/stdc++.h>
using namespace std;

int i, A, B, C, D;

bool a(int x){
  return (D or !(!B and (A^C)));
}

bool b(int x){
  return !(C and (A^B));
}

bool c(int x){
  return (C or !B or A);
}

bool d(int x){
  return (D or ((!A)^(!(B or !C))) or !(!B or C));
}

bool e(int x){
  return !(A or !(B or !C));
}

bool f(int x){
  return (D or !(B or !C) or  !(A or !(C or !B)));
}

bool g(int x){
  return !(!D and !(C and !A)) or (C^B);
}

void print(string s){
  if(s[0] == '1') cout << " ----- ";
  cout << endl;
  cout << (s[1] == '1' ? "|" : " ");
  if(s[2] == '1') cout << "     |";
  cout << endl;
  if(s[3] == '1') cout << " ----- ";
  cout << endl;
  cout << (s[4] == '1' ? "|" : " ");
  if(s[5] == '1') cout << "     |";
  cout << endl;
  if(s[6] == '1') cout << " ----- ";
  cout << endl;
}

void go(int i){ 
    string aux;
    A = (i & 1) ? 1 : 0;
    B = (i & 2) ? 1 : 0;
    C = (i & 4) ? 1 : 0;
    D = (i & 8) ? 1 : 0;
    cout << A << " " << B << " " << C << " " << D << endl;
    aux += to_string(a(i)) + to_string(f(i)) + to_string(b(i)) + to_string(g(i)) + to_string(e(i)) + to_string(c(i)) + to_string(d(i)); 
   //
   //aux += to_string(a(i)) + to_string(b(i)) + to_string(c(i)) + to_string(d(i)) + to_string(e(i)) + to_string(f(i)) + to_string(g(i));
  // cout << aux << endl;
     print(aux);
}

int main(){
  cin >> i;
  go(i);
}
