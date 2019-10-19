#include <bits/stdc++.h>
using namespace std;

class Fraction{
  int m_num;
  int m_den;
  public:
    Fraction(int num, int den) : m_num(num), m_den(den){
        if(!den) throw string("Error");
    }
};

int main(){
  try{
    Fraction a{1, 0};
  }
  catch (string s) {
    cout << s << endl;
  }
}
