#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 1e5 + 5;

int q[N], i = -1, f = -1;

void push(int x){
  if((f+1)%N == i) return;
  if(i == -1) i = f = 0;
  else f = (f+1)%N;
  q[f] = x;
}

int pop(){
  if(i == -1) return INF;
  if(i == f){
    int aux = q[i];
    i = f = -1;
    return aux;
  }
  int aux = q[i];
  i = (i+1)%N;
  return aux;
}

int main(){
  push(3);
  push(2);
  push(155);
  cout << pop() << endl;
  cout << q[i] << endl;
  cout << q[f] << endl;
}
