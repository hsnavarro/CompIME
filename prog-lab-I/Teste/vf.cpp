#include <bits/stdc++.h>
using namespace std;

int f(){
  static int x = 1;
  x = 10 + (x + 1)%9;
  return (x%2)?(x|=0x01):(x &= 0xFE);
}

bool g(int x) {return !(x%3); }
bool h(int x) { return !(x <= 17); }
bool c(int x1, int x2) { return x1>x2;}

int main(){
  vector<int> v(10);
  generate_n(v.begin(), 10, f);
  for(int i = 0; i < 10; i++) cout << v[i] << " ";
  cout << endl;
  
  srand(472016);
  random_shuffle(v.begin(), v.end());
  cout << count_if(v.begin(), v.end(), g) << endl;
  cout << *(find_if(v.begin(), v.end(), h)) << endl;
  
  stack<int> s;
  for(int i = 0; i < 10; s.push(v[i++]));
  v.clear();
  for(; !s.empty(); v.push_back(s.top()), s.pop());
  sort(v.begin(), v.end(), c);
  for(int i = 0; i < 10; i++) cout << v[i] << " ";
  cout << endl;

}
