#include <bits/stdc++.h>
using namespace std;

#define TAM_TAB 8
enum tcor{azul, vermelha};
class peca{
  protected:
    int linha, coluna;
    tcor cor;
    peca(int linha, int coluna, tcor cor):
      linha(linha), coluna(coluna), cor(cor){}
    bool movimentar(int novalinha, int novacoluna){
      return !(novalinha < 0 || novalinha > TAM_TAB-1 || novacoluna < 0 || novacoluna > TAM_TAB-1);
    }
};

class amazona : public peca {
  public:
    amazona(int linha, int coluna, tcor cor): peca(linha, coluna, cor) {}
    bool movimentar(int novalinha, int novacoluna){
      if(!peca::movimentar(novalinha, novacoluna) or 
          abs(novalinha-linha) != abs(novacoluna-coluna))
        return false;
      
      linha = novalinha;
      coluna = novacoluna;
      return true;
    }
};

class cavaleiro : public peca {
  private:
    int movimentos;
    cavaleiro(int linha, int coluna, tcor cor, int mov):
      peca(linha, coluna, cor), movimentos(0) {}
    bool movimentar(int novalinha, int novacoluna){
      if(!peca::movimentar(novalinha, novacoluna) or novacoluna != coluna)
        return false;
      if(!movimentos and abs(novalinha - linha) != 2) return false;
      if(movimentos and abs(novalinha - linha) != 1) return false;
      
      movimentos++;
      linha = novalinha;
      return true;
    }
};

int main(){


}
