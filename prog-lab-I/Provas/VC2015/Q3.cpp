#include <bits/stdc++.h>
using namespace std;

class Empregado{
  private:
    string nome;
    int numCracha;
    float salarioBase;
  public:
    Empregado(string s, int n, float val) : nome(s), numCracha(n), salarioBase(val){}
   
    string getNome(){
      return nome;
    }

    int getNumCracha(){
      return numCracha;
    }

    float getSalarioBase(){
      return salarioBase;
    }
};

class Mensalista : public Empregado {
  private:
      float imposto;
  public:
      Mensalista(string s, int n, float val, float imposto) : Empregado(s, n, val), imposto(imposto) {}

      float getSalarioLiquido(){
        return getSalarioBase() - imposto*getSalarioBase();
      }
};

class Horista : public Empregado {
  private:
    float horasTrabalhadas;
  public:
    Horista(string s, int n, float val, float hrs) : Empregado(s, n, val), horasTrabalhadas(hrs) {}

    float getSalarioLiquido(){
      return getSalarioBase()*horasTrabalhadas;
    }
};

class Comissionado : public Empregado{
  private:
    int numVendas;
  public:
    Comissionado(string s, int n, float val, float vend) : Empregado(s, n, val), numVendas(vend) {}

    float getSalarioLiquido(){
      return getSalarioBase()*1.0*numVendas;
    }

};

int main(){
  Horista Maria("Maria", 1, 100.0, 2.5);
  cout << Maria.getSalarioLiquido() << endl;
}
