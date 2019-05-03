#include <bits/stdc++.h>
using namespace std;

// agregação: do tipo "tem um"
class Motor{
  public:
    int cavalos;
    int ano;
};

class Carro{
  public:
    int valor;
    Motor motor;
};

// herança: do tipo "é um"
class Animal{
  public:
    int idade;
    int nome;
};

class Cavalo: public Animal{
  public:
    int velocidade;
};

int main(){

}
