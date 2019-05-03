#include <bits/stdc++.h>
using namespace std;

int hanoi(int n, char a, char b, char c){
  if(n == 1) return cout << "Move 1 from " << a << " to " << b << endl, 0;
  hanoi(n-1, a, c, b);
  cout << "Move " << n << " from " << a << " to " << b << endl;
  hanoi(n-1, c, b, a);
}

int main(){
  hanoi(3, 'A', 'B', 'C');
}
