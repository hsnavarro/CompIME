#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int sz, l[N];

// O(n)
int search(int key){
  if(!sz) return -1;
  for(int i = 0; i < sz; i++) if(l[i] == key) return i;
  return -1;
}

// O(n)
void remove(int key){
  int i = search(key);
  if(i == -1) return;
  for(int j = i + 1; j < sz; j++) l[j-1] = l[j];
  sz--;
}

// O(n)
void insert(int key){
  if(sz == N) return;
  int i = search(key);
  if(i == -1) l[sz] = key, sz++;
}

void print(){
  for(int i = 0; i < sz; i++) cout << l[i] << " ";
  cout << endl;
}

int main(){
  insert(1);
  print();
  insert(2);
  print();
  remove(1);
  print();
}
