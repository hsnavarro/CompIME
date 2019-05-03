#include <bits/stdc++.h>
using namespace std;

enum sentido {DIRETA, INVERSA}; 

class elemento{
  public:
    int chave;
    elemento *prox;
    elemento() : prox(nullptr) {}
};

class listaEncadeada{
  public:
    elemento *inicio;

    listaEncadeada() : inicio(nullptr) {}
    ~listaEncadeada(){
      elemento *p;
      while(inicio != nullptr){
        p = inicio -> prox;
        delete inicio;
        inicio = p;
      }
    }

    bool inserir(int v, int k){
      elemento *p = inicio;
      if(!k){
        elemento *novo = new elemento();
        novo -> chave = v;
        novo -> prox = inicio;
        inicio = novo;
        return true;
      }
      
      for(int cnt = 1; ; p = p -> prox, cnt++){
        if(p == nullptr and cnt != k) return false;
        if(cnt == k){
          elemento *novo = new elemento();
          novo -> prox = p -> prox;
          p -> prox = novo;
          novo -> chave = v;
          return true;
        }
      }
    }

    bool remover(int k){
      if(!k) return false;
      elemento *ant = nullptr;
      elemento *p = inicio;

      for(int cnt = 1; ; ant = p, p = p -> prox, cnt++){
        if(p == nullptr and cnt != k) return false;
        if(cnt == k and k != 1){
          ant -> prox = p -> prox;
          delete p;
        }
        if(cnt == k and k == 1){
          elemento *aux = inicio;
          inicio = inicio -> prox;
          delete aux;
        }
      }
    }

    void imprimir(sentido lado){
      vector<int> v;
      elemento *p = inicio;
      for(p; p != nullptr; p = p -> prox) v.push_back(p -> chave);
      if(lado == DIRETA) for(auto x : v) cout << x << " ";
      if(lado == INVERSA) for(int i = v.size() - 1; i >= 0; i--) cout << v[i] << " ";
      cout << endl;
      v.clear();
    }
};

int main(){
  listaEncadeada a;
  a.inserir(0, 0);
  a.inserir(3, 0);
  a.imprimir(DIRETA);
  a.imprimir(INVERSA);
}
