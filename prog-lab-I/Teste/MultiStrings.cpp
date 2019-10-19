#include <bits/stdc++.h>
using namespace std;

struct MultiStrings{
  char nome1[20];
  string nome2;
  ostringstream nome3;
};

bool salvabin(MultiStrings &ms, char *nomeDoArquivo){
  ofstream arq(nomeDoArquivo, ios::binary);
  if(!arq.is_open()) return false;
  int tam1 = strlen(ms.nome1);
  int tam2 = ms.nome2.size();
  int tam3 = ms.nome3.str().size();
  arq.write((char*) &tam1, sizeof(int));
  arq.write(ms.nome1, tam1*sizeof(char));
  arq.write((char*) &tam2, sizeof(int));
  arq.write(ms.nome2.c_str(), tam2*sizeof(char));
  arq.write((char*) &tam3, sizeof(int));
  arq.write(ms.nome3.str().c_str(), tam3*sizeof(char));

  if(!arq.good()) return false;
  arq.close();
  return true;
}

bool carregabin(MultiStrings &ms, char *nomeDoArquivo){
  ifstream arq(nomeDoArquivo, ios::binary);
  if(!arq.is_open()) return false;
  int tam;
  string s;
  for(int i = 0; i < 3; i++){
    int tam;
    arq.read((char*) &tam, sizeof(int));
    s.resize(tam);
    arq.read(&s[0], tam*sizeof(char));
    if(i == 0) strcpy(ms.nome1, s.c_str());
    if(i == 1) ms.nome2 = s;
    if(i == 2) ms.nome3 << s;
  }
  
  if(!arq.good()) return false;
  return true;
}

int main(){
  MultiStrings a1, b;
  strcpy(a1.nome1, "balao");
  a1.nome2 = "abacaxi";
  a1.nome3 << "oioi";
  string nome = "testeMulti";
  salvabin(a1, &nome[0]);
  carregabin(b, &nome[0]);
  string s = string(b.nome1);
  cout << s << endl;
  cout << b.nome2 << endl;
  cout << b.nome3.str() << endl;
}
