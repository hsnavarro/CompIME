#include <bits/stdc++.h>
using namespace std;

class Complex{
  public:
    double re, im;
    Complex(double, double);
    double abs();
    Complex conj();
    void print();
    Complex add(Complex);
    Complex sub(Complex);
    Complex mult(Complex);
    Complex div(Complex);
};

Complex::Complex(double re, double im) : re(re), im(im) {}

double Complex::abs(){
 // Complex a = {this->re, this->im};
  return sqrt(re*re + im*im);
}

Complex Complex::conj(){
  Complex a = {this->re, -1*(this->im) };
  return a;
}

void Complex::print(){
  if(this->im >= 0) 
    cout <<  this->re << "+" << this->im << "i" << endl;
  else
    cout << this->re << this->im << "i" << endl;
}

Complex Complex::add(Complex b){
  Complex a = { this->re + b.re, this->im + b.im };
  return a;
}

Complex Complex::sub(Complex b){
  Complex a = { this->re - b.re, this->im - b.im };
  return a;
}

Complex Complex::mult(Complex b){
  Complex a = { this->re*b.re - this->im*b.im, this->re*b.im + this->im*b.re };
  return a;
}

Complex Complex::div(Complex b){
  Complex aux = *this;
  Complex a = aux.mult(b.conj());
  double abs = b.abs();
  abs *= abs;
  return { a.re/abs, a.im/abs };
}

int main(){
  double a, b;
  cout << "Insira o número imaginário: " << endl;
  cin >> a >> b;
  Complex a1 = Complex(a, b);
  cout << "Número : " << endl;
  a1.print();
  cout << "Módulo: " << endl;
  cout << a1.abs() << endl;
  Complex conj = a1.conj();
  cout << "Conjugado: " << endl;
  conj.print();
  
  cout << "Insira o número que deseja operar: " << endl;
  cin >> a >> b;
  Complex a2 = Complex(a, b);

  Complex add = a1.add(a2);
  cout << "Somado: " << endl;
  add.print();

  Complex sub = a1.sub(a2);
  cout << "Subtraído: " << endl;
  sub.print();

  Complex mult = a1.mult(a2);
  cout << "Multiplicado: " << endl;
  mult.print();

  Complex div = a1.div(a2);
  cout << "Dividido: " << endl;
  div.print();
}


