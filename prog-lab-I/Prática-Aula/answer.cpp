#include <iostream>

using std::cout;
using std::string;
using std::endl;

class SuperPoder{
private:
		string nome;
		int categoria;
public:
		string getNome(){return nome;}
		int getCategoria(){return categoria;}
		SuperPoder(string nome, int categoria){
				this->nome = nome;
				this->categoria = categoria;
		}
};

class Personagem{
private:
		string nome, nomeVidaReal;
		SuperPoder **poderes;
		int nPoderes;
protected:
		Personagem(string nome, string nomeVidaReal){
				this->nome = nome;
				this->nomeVidaReal = nomeVidaReal;
				poderes = new SuperPoder*[4];
				nPoderes = 0;
		}
public:
		~Personagem(){
				delete []poderes;
		}
    /*
		Personagem(const Personagem& p){
			nome = p.nome;
			nomeVidaReal = nomeVidaReal;
			poderes = new SuperPoder*[4];
			nPoderes = p.nPoderes;
  			for (int i=0;i<nPoderes;i++)
	  			poderes[i] = p.poderes[i];

		}
    */
		string getNome(){
			return nome;
		}
        bool adicionarSuperPoder(SuperPoder& sp){
				if (nPoderes>=4)
					return false;
				poderes[nPoderes++] = &sp;
				return true;
		}
		virtual double getPoderTotal(){
			double poderTotal = 0;
			for (int i=0;i<nPoderes;i++){
				poderTotal += poderes[i]->getCategoria();
			}
			return poderTotal;
		}
};

class SuperHeroi:public Personagem{

public:
	 SuperHeroi(string nome, string nomeVidaReal):Personagem(nome, nomeVidaReal){
	 }
	 double getPoderTotal(){
	     return 1.1*Personagem::getPoderTotal();
	 }
};

class Vilao:public Personagem{
		int tempoPrisao;
public:
	  Vilao(string nome, string nomeVidaReal, int tempoPrisao):Personagem(nome, nomeVidaReal){
				this->tempoPrisao = tempoPrisao;
		}
	double getPoderTotal(){
		return (1.0 + 0.01*tempoPrisao)*Personagem::getPoderTotal();
	}
};

class Confronto{
public:
		string executar(Personagem &p1, Personagem &p2){
				double a = p1.getPoderTotal(), b = p2.getPoderTotal();
				//cout << "*" << a << " " << b << " ";
				if (a > b)
					return p1.getNome();
				else
				if (a < b)
					return p2.getNome();
				else
				  return "Empate";

		}
};

int main(){

		SuperPoder s1("soltar teia", 3);
		SuperPoder s2("andar em paredes", 2);
		SuperPoder s3("sentido apurado", 1);
		SuperPoder s4("velocidade", 5);
		SuperPoder s5("Voar", 3);
		SuperPoder s6("força", 5);
		SuperPoder s7("visão de raio X", 4);
		SuperPoder s8("sopro congelante", 4);
		SuperPoder s9("supersoldado", 3);
		SuperPoder s10("escudo", 3);
		SuperPoder s11("anel magico", 5);
		SuperPoder s12("armadura", 4);
		SuperPoder s13("dispositivos eletronicos", 2);
		SuperPoder s14("mente aguçada", 5);
		SuperPoder s15("tentáculos indestrutíveis", 5);
		SuperPoder s16("velocidade", 1);

		SuperHeroi ha("Homem-Aranha", "Peter Park");
		SuperHeroi sh("Super-Homem", "Clark Kent");
		SuperHeroi ca("Capitão América", "Steven Rogers");
		SuperHeroi fl("Flash", "Barry Allen");
		SuperHeroi lv("Lanterna-Verde", "Hal Jordan");
		SuperHeroi hf("Homem de Ferro", "Tony Stark");

		Vilao dv("Duende Verde", "Norman Osbourne", 3);
		Vilao ll("Lex Luthor", "Lex Luthor", 5);
		Vilao bi("Bizarro", "Bizarro", 11);
		Vilao oc("Octopus", "Otto Octavius", 4);

		ha.adicionarSuperPoder(s1);
		ha.adicionarSuperPoder(s2);
		ha.adicionarSuperPoder(s3);

		sh.adicionarSuperPoder(s5);
		sh.adicionarSuperPoder(s6);
		sh.adicionarSuperPoder(s7);
		sh.adicionarSuperPoder(s8);

		ca.adicionarSuperPoder(s9);
		ca.adicionarSuperPoder(s10);

		fl.adicionarSuperPoder(s4);

		lv.adicionarSuperPoder(s11);

		hf.adicionarSuperPoder(s12);
		hf.adicionarSuperPoder(s13);


		dv.adicionarSuperPoder(s6);

		ll.adicionarSuperPoder(s14);

		bi.adicionarSuperPoder(s5);
		bi.adicionarSuperPoder(s6);
		bi.adicionarSuperPoder(s7);
		bi.adicionarSuperPoder(s8);

		oc.adicionarSuperPoder(s15);
		oc.adicionarSuperPoder(s16);

		Vilao viloes[4] = {dv, ll, bi, oc};
	    SuperHeroi herois[6] = {ha, sh, ca, fl, lv, hf};

		for (int i=0; i<6;i++)
			for (int j=0; j<4;j++){
					cout << herois[i].getNome();
					cout << " X ";
					cout << viloes[j].getNome();
					cout << " -> ";

					cout << Confronto().executar(herois[i], viloes[j]) << endl;
			}

		for (int i=0; i<6;i++)
			for (int j=i; j<6;j++){
					cout << herois[i].getNome();
					cout << " X ";
					cout << herois[j].getNome();
					cout << " -> ";

					cout << Confronto().executar(herois[i], herois[j]) << endl;
			}

		for (int i=0; i<4;i++)
			for (int j=i; j<4;j++){
					cout << viloes[i].getNome();
					cout << " X ";
					cout << viloes[j].getNome();
					cout << " -> ";

					cout << Confronto().executar(viloes[i], viloes[j]) << endl;
			}

}
