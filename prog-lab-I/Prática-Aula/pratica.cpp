#include <bits/stdc++.h>
using namespace std;

class Superpoder{
  private:
    string nome;
    int categoria;
  public:
    string getNome() { return nome; }
    int getCategoria() { return categoria; }
    Superpoder(string n, int cat) : nome(n), categoria(cat) { }
};

class Personagem{
  private:
    string nome;
    string nomeVidaReal;
    vector<Superpoder> poderes;
  public:
    bool adicionaSuperpoder(Superpoder &sp){
      if(poderes.size() == 4) return false;
      poderes.push_back(sp);
      return true;
    }

    double getPoderTotal(){
      double sum = 0;
      for(auto poder : poderes) sum += poder.getCategoria()*1.0;
      return sum;
    }

    string getNome() { return nome; }
  protected:
    Personagem(string n, string nVR) : nome(n), nomeVidaReal(nVR) { } 
};

class SuperHeroi : public Personagem {
  public:
    SuperHeroi(string n, string nVR) : Personagem(n, nVR) { }
    
    double getPoderTotal(){
      return Personagem::getPoderTotal()*1.1;
    }
};

class Vilao : public Personagem {
  private:
    int tempoDePrisao;
  public:
    Vilao(string n, string nVR, int tDP) : Personagem(n, nVR), tempoDePrisao(tDP) { }

    double getPoderTotal(){
      return Personagem::getPoderTotal()*(1.0 + tempoDePrisao*0.01);
    }
};

class Confronto{
  public:
    string enfrentar(SuperHeroi &p1, Vilao &p2){
      double poderHeroi = p1.getPoderTotal();
      double poderVilao = p2.getPoderTotal();
      if(poderHeroi == poderVilao) return "empate";
      return poderHeroi > poderVilao ? p1.getNome() : p2.getNome();
    }
};

int main(){
 SuperHeroi homem_aranha("Homem-Aranha", "Peter Park");
 SuperHeroi super_homem("Super-Homem", "Clark Kent");
 SuperHeroi cap_america("Capitão América", "Steven Rogers");
 SuperHeroi flash("Flash", "Barry Allen");
 SuperHeroi lanterna_verde("Lanterna-Verde", "Hal Jordan");
 SuperHeroi homem_de_ferro("Homem de Ferro", "Tony Stark");

 Vilao duende_verde("Duende Verde", "Norman Osbourne", 3);
 Vilao lex_luthor("Lex Luthor", "Lex Luthor", 5);
 Vilao bizarro("Bizarro", "Bizarro", 11);
 Vilao octopus("Octopus", "Otto Octavius", 4);

 Superpoder a1("soltar teia", 3);
 Superpoder a2("andar em paredes", 2);
 Superpoder a3("sentido apurado", 1);
 Superpoder a4("voar", 3);
 Superpoder a5("força", 5);
 Superpoder a6("visão de raio X", 4);
 Superpoder a7("sopro congelante", 4);
 Superpoder a8("supersoldado", 3);
 Superpoder a9("escudo", 3);
 Superpoder a10("velocidade", 5);
 Superpoder a11("anel mágico", 5);
 Superpoder a12("armadura", 4);
 Superpoder a13("dispositivos eletrônicos", 2);
 Superpoder a14("mente aguçada", 5);
 Superpoder a15("tentáculos indestrutíveis", 5);
 Superpoder a16("velocidade", 1);

 vector<Superpoder> poderes = {a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16};

 for(int i = 0; i < 3; i++) homem_aranha.adicionaSuperpoder(poderes[i]);
 for(int i = 3; i < 7; i++) super_homem.adicionaSuperpoder(poderes[i]);
 for(int i = 7; i < 9; i++) cap_america.adicionaSuperpoder(poderes[i]);
 flash.adicionaSuperpoder(poderes[9]);
 lanterna_verde.adicionaSuperpoder(poderes[10]);
 for(int i = 11; i < 13; i++) homem_de_ferro.adicionaSuperpoder(poderes[i]);

 duende_verde.adicionaSuperpoder(poderes[4]);
 lex_luthor.adicionaSuperpoder(poderes[13]);
 for(int i = 3; i < 7; i++) bizarro.adicionaSuperpoder(poderes[i]);
 for(int i = 14; i < 16; i++) octopus.adicionaSuperpoder(poderes[i]);

 vector<SuperHeroi> herois = {homem_aranha, super_homem, cap_america, flash, lanterna_verde, homem_de_ferro};

 vector<Vilao> viloes = {duende_verde, lex_luthor, bizarro, octopus};

 Confronto a;
  for(auto heroi : herois)
    for(auto vilao : viloes)
      cout << heroi.getNome() << " X " << vilao.getNome() << " -> " << 
        a.enfrentar(heroi, vilao) << endl;
}
