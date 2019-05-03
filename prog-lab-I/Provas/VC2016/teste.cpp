#include <bits/stdc++.h>
using namespace std;

class A{
  public:
    int val;
    A(int val) : val(val) {}
};

int f(A &a1, A *a2, A a3){
  a1.val++;
  a2++;
  a3.val++;
}

int main(){
  A a1(3), a2(a1);
  A &a3 = a1;
  a3.val += a1.val + (++a2.val);
  cout << a1.val << "-" << a2.val << "-" << a3.val << endl;

  f(a2, &a3, a1);

  cout << ++a1.val << "-" << a2.val << endl;
}
