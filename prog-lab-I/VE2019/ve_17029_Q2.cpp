// Feito por Henrique Navarro - 17029
#include<bits/stdc++.h>
using namespace std;

// usando funcionalidades do C++11
class burrowsWheelerInverso{
  string revertida;
  public:
    burrowsWheelerInverso(string revertida) : revertida(revertida) {}
    string getRevertida (){
      return revertida;
    }
    void inversa(){
      vector<string> rotacoes(revertida.size());
      for(int i = 0; i < revertida.size(); i++) rotacoes[i] += revertida[i];
      while(rotacoes[0].size() != revertida.size()){
        sort(rotacoes.begin(), rotacoes.end());
        for(int i = 0; i < revertida.size(); i++) 
          rotacoes[i] = revertida[i] + rotacoes[i];
      }
      string ans;
      //C++ 11
      for(auto x : rotacoes){
        if(x[0] == '^' and x.back() == '|') {
          ans = x;
          break;
        }
      }
      ans = ans.substr(1, ans.size() - 2);
      revertida = ans;
    }
};

int main(){
  burrowsWheelerInverso A("BNN^AA|A");
  A.inversa();
  cout << A.getRevertida() << endl;
}
