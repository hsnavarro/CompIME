// Feito por Henrique Navarro - 17029
#include<bits/stdc++.h>
using namespace std;

// usando funcionalidades do C++11
class redeAmigos{
  vector<string> amigos;
  int calculaAmigos(string &in, vector<string> &aux){
    // C++ 11
    int qntAmigos = 0;
    map<char, int> freq;
    // C++ 11
    for(auto word : aux){
      for(auto letter : word) freq[letter]++;
      for(auto letter : in) if(freq[letter]) {
        qntAmigos++;
        break;
      }
      freq.clear();
    }
    return max(qntAmigos-1, 0);
  }
  public:
    int getSize(){
      return amigos.size();
    }
    int insere(string interesses){
      amigos.push_back(interesses);
      return calculaAmigos(interesses, amigos);
    }
    double numMedio(){
      double sum = 0.0;
      for(int i = 0; i < amigos.size(); i++) 
        sum += 1.0*calculaAmigos(amigos[i], amigos);
      return sum/amigos.size();
    }
};

class redeInvertida : public redeAmigos {
  public:
    int insere(string interesses){
      int ans = redeAmigos::insere(interesses);
      return getSize() - ans - 1;
    }
    double numMedio(){
      double ans = redeAmigos::numMedio();
      return 1.0*getSize() - ans - 1.0;
    }
};

int main(){
  redeAmigos A;
  redeInvertida B;
  cout << A.insere("ABC") << endl;
  cout << A.insere("DE") << endl;
  cout << A.insere("FGHIJA") << endl;
  cout << A.getSize() << endl;
  cout << setprecision(15) << fixed << A.numMedio() << endl;
 
  cout << B.insere("ABC") << endl;
  cout << B.insere("DE") << endl;
  cout << B.insere("FGHIJA") << endl;
  cout << B.getSize() << endl;
  cout << setprecision(15) << fixed << B.numMedio() << endl;

}
