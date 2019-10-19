#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct Set{
  T* set1;
  int size;

  Set() : size(0) {}

  void insert(T x){
    size++;
    set1 = (T*) realloc(set1, size*sizeof(T));
    set1[size-1] = x;
  }
};

int main(){




}
