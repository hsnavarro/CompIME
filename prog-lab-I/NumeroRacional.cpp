#include <bits/stdc++.h>
using namespace std;

class NumeroRacional {
  int m_num;
  int m_den;
  public:
    NumeroRacional (int num, int den) :
      m_num(num), m_den(den) {
      try{ 
        if(!den) throw string("Error!");
      }
      catch(string s) {
        cout << s << endl;
      }
      if(num * den <= 0) num = -abs(num), den = abs(den);
      int mdc = __gcd(abs(num), abs(den));
      num /= mdc;
      den /= mdc;
    }

   NumeroRacional operator+ (const NumeroRacional &b) const{
      int num = m_num*b.m_den + b.m_num*m_den;
      int den = m_den*b.m_den;
      return NumeroRacional(num, den);
   }

   NumeroRacional operator/ (const NumeroRacional &b) const{
      int num = m_num*b.m_den;
      int den = m_den*b.m_num;
      return NumeroRacional(num, den);
   }

   NumeroRacional operator++ (){
      m_num += m_den;
      return *this;
   }

   NumeroRacional operator++ (int){
    NumeroRacional aux(*this);
    m_num += m_den;
    return aux;
   }

   operator float (){
    return float(m_num)/m_den;
   }

   friend ostream& operator<< (ostream&, NumeroRacional&);
};

ostream& operator<< (ostream& out, NumeroRacional& b){
  out << b.m_num << "/" << b.m_den;
  return out;
}

int main(){
  NumeroRacional a(2, 3);
  NumeroRacional b(1, 1);
  b = ++a;
  cout << b << endl;
  cout << a << endl;
}
