#include <bits/stdc++.h>
using namespace std;

struct Pessoa {
  string nome;
  int idade;
};

bool gravar(vector<Pessoa> &v, string nomeDoArquivo){
  ofstream arq(nomeDoArquivo.c_str(), ios::binary);
  int n = v.size();
  arq.write((char*)&n, 1);
  arq.write((char*)&v[0], n*sizeof(Pessoa));
  v.clear();
}

bool carregar(vector<Pessoa> &v, string nomeDoArquivo){
  ifstream arq(nomeDoArquivo.c_str(), ios::binary);
  int tam;
  arq.read((char*)&tam, 1);
  v.resize(tam);
  arq.read((char*)&v[0], tam*sizeof(Pessoa));
}

int main(){
  Pessoa a {"Ivan", 13}, b { "Henrique", 17}, c { "Eduardo", 21 };
  vector<Pessoa> v = {a, b, c};
  gravar(v, "teste");
  for(auto x : v) cout << x.nome << " " << x.idade << endl;
  carregar(v, "teste");
  for(auto x : v) cout << x.nome << " " << x.idade << endl;
}
