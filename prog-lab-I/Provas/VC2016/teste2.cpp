#include <iostream>

int f1 (int &a){
  return a + 3;
}

int f2 (int b){
  b >>= 3;
  return b;
}

int f3(int *c){
  return (((*c)%2) ? ((*c)/2) : ((*c)*2));
}

int main(){
  for(int i = 0; i < 12; ){
    std::cout << f3(&i) << ", " << f2(i) << ", " << (i = f1(i)) << std::endl;
  }
}
