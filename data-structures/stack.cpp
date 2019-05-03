#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 1e5 + 5;

int top = -1, st[N];

// O(1)
void push(int x){
  if(top == N-1) return;
  top++, st[top] = x;
}

// O(1)
int pop(){
  if(top == -1) return INF;
  return st[top--];
}

int main(){
  push(1);
  push(2);
  cout << st[top] << endl;
  pop();
  cout << st[top] << endl;
}
