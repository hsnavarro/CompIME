#include <bits/stdc++.h>
using namespace std;

int i, A, B, C, D;

bool a(int x){
  return (!A and C) or (B and C) or (C and !D) or (A and !B and !C) 
    or (A and !C and !D) or (!B and !C and !D) or (!A and B and D);
}

bool b(int x){
  return (!B and !C) or (!A and !B) or (C and D and !A) or
    (!C and !D and !A) or (C and !D and !B) or (!C and D and A);
}

bool c(int x){
  return (C and !D) or (A and !B) or (A and D) or
    (!A and !B and C) or (!A and B and !C);
}

bool d(int x){
  return (A and !B) or (A and C) or (!C and !D) or (B and !D) or
    (!A and B and !C);
}

bool e(int x){
  return (A and !B) or (!A and B) or (!C and D) or (!A and !C) or (!A and D);
}

bool f(int x){
  return (A and !C) or (!C and !D and !B) or (B and !C and D) or
    (C and !D and B) or (!A and !B and C) or (C and D and !B);
}

bool g(int x){
  return (A and B) or (C and !D) or (A and C) or (!B and !C and !D);
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
    A = i & (1 << 3);
    B = i & (1 << 2);
    C = i & (1 << 1);
    D = i & (1 << 0);
    aux += to_string(a(i)) + to_string(d(i)) + to_string(b(i)) + to_string(c(i)) + to_string(g(i)) + to_string(e(i)) + to_string(f(i)); 
    print(aux);
}

int main(){
  cin >> i;
  go(i);
}
