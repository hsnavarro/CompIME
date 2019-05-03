#include <bits/stdc++.h>
using namespace std;

class Data{
  private:
    int dia, mes, ano;
  public:
  Data() : dia(1), mes(1), ano(2019) {}
  Data(int dia, int mes, int ano) : dia(dia), mes(mes), ano(ano) {}
  int getDia() { return dia; }
  int getMes() { return mes; }
  int gesAno() { return ano; }
  void reiniciar(int d, int m, int a){
    dia = d;
    mes = m;
    ano = a;
  }

  void adiantar(int d, int m, int a){
    dia = d;
    mes = m;
    ano = a;
  }

  void imprimir(){
    cout << 
  }



};

int main(){


}
