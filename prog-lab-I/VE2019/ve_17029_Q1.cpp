// Feito por Henrique Navarro - 17029
#include<bits/stdc++.h>
using namespace std;

// usando funcionalidades do C++11
class burrowsWheeler{
  string palavra;
  string modificarEntrada(){
    return '^' + palavra + '|';
  }
  vector<string> rotacoes(string modificada){
    vector<string> resposta;
    resposta.push_back(modificada);
    while(true){
      char ultima = modificada.back();
      modificada = ultima + modificada;
      modificada.pop_back();
      if(modificada == resposta[0]) break;
      resposta.push_back(modificada);
    }
    return resposta;
  }
  vector<string> ordena(vector<string> rotacoes){
    sort(rotacoes.begin(), rotacoes.end());
    return rotacoes;
  }
  string destacaColuna(vector<string> ordenado){
    string ans;
    //C++ 11
    for(auto x : ordenado) ans += x.back();
    return ans;
  }
  
  public:
    burrowsWheeler(string palavra) : palavra(palavra) {}
    string getPalavra() {
      return palavra;
    }
    void transformada(){
      vector<string> rot = rotacoes(modificarEntrada());
      rot = ordena(rot);
      palavra = destacaColuna(rot);
    }
};

int main(){
  burrowsWheeler A("BANANA");
  A.transformada();
  cout << A.getPalavra() << endl;
}
