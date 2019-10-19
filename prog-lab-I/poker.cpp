#include <bits/stdc++.h>

using namespace std;

enum figura {DOIS, TRES, QUATRO, CINCO, SEIS, SETE, OITO,
 NOVE, DEZ, VALETE, DAMA, REI, AS};
enum simbolo {OUROS, ESPADAS, COPAS, PAUS};

string figuras[13] = {" 2", " 3", " 4", " 5", " 6", " 7", " 8", " 9",
 "10", "VA", "DA", "RE", "AS"};
char simbolos[4] = {"O", "E", "C", "P"};

figura f;

struct Carta{
    figura valor;
    simbolo naipe;
    Carta operator++(int){
        Carta temp(*this);
        if (valor != AS) valor = (figura)(valor + 1);
        else{
            valor = dois;
            if (naipe == PAUS) naipe = OUROS;
            else naipe = (simbolo)(naipe + 1);
        }
        return temp;
    }
};

ostream& operator<<(ostream &os, const Carta &carta){
    os << figuras[carta.valor] << simbolos[carta.naipe];
    return os;
}

Carta proximaCarta(){
    static Carta c = {DOIS,OUROS};
    return c++;
}

template <class T>
void imprimir(vector<T> v){
    for(auto x : v) cout << x << " ";
    cout << endl;
}

bool conta_f(const Carta &c){
    return c.valor == f;
}

int main(){
    srand(time(NULL));
    vector<Carta> baralho(52);

    generate_n(baralho.begin(), 52, proximaCarta);
/*
    cout << "Baralho:\n";
    imprimir(baralho);
    cout << endl;
*/
    random_shuffle(baralho.begin(), baralho.end());

    cout << "Baralho:\n";
    imprimir(baralho);
    cout << endl;

    vector< vector<Carta> > maos(4);
    vector<Carta> mesa;
    vector< vector<Carta> >::iterator it;
    vector<Carta>::iterator it2;

    for (unsigned k=0;k<2;k++)
        for (it = maos.begin();it!=maos.end();it++){
            Carta c = *(baralho.rbegin());
            baralho.pop_back();
            it->push_back(c);
        }
    //joga fora
    baralho.pop_back();
    //monta flop
    mesa.push_back(*(baralho.rbegin()));
    baralho.pop_back();
    mesa.push_back(*(baralho.rbegin()));
    baralho.pop_back();
    mesa.push_back(*(baralho.rbegin()));
    baralho.pop_back();
    //joga fora
    baralho.pop_back();
    //monta turn
    mesa.push_back(*(baralho.rbegin()));
    baralho.pop_back();
    //joga fora
    baralho.pop_back();
    //monta river
    mesa.push_back(*(baralho.rbegin()));
    baralho.pop_back();

    unsigned m = 1;
    for (it = maos.begin();it!=maos.end();it++){
        it->reserve(it->size()+distance(mesa.begin(),mesa.end()));
        it->insert(it->end(), mesa.begin(), mesa.end());
        cout << "Mao " << m++ << ": ";
        imprimir(*it);
    }

    cout << "Mesa :         ";
    imprimir(mesa);

    m = 1;
    for (it = maos.begin();it!=maos.end();it++){
        int nduplas = 0, ntrincas = 0, nquadras = 0;
        for (f=dois;f<=as;f = (figura)(f+1)){
            int conta = count_if(it->begin(), it->end(),
                                 conta_f);
            switch (conta){
                case 2:
                    cout << "Mao " << m <<
                     " possui dupla de " <<
                     figuras[f] << endl;
                    nduplas++;
                break;
                case 3:
                    cout << "Mao " << m <<
                     " possui trinca de " <<
                     figuras[f] << endl;
                    ntrincas++;
                break;
                case 4:
                    cout << "Mao " << m <<
                     " possui quadra de " <<
                     figuras[f] << endl;
                    nquadras++;
                break;
            }
        }
        if (nquadras>0 && (nduplas>0 || ntrincas>0))
            cout << "Mao " << m <<
             " possui Full House" << endl;
        else
        if (ntrincas>0 && nduplas>0)
            cout << "Mao " << m <<
             " possui Full House" << endl;
        else
        if (ntrincas>1)
            cout << "Mao " << m <<
             " possui Full House" << endl;

        m++;
    }

/*
    cout << "Baralho:\n";
    imprimir(baralho);
    cout << endl;

    Carta c;
    c.valor = valete;
    c.naipe = ouros;

    cout << c << endl;
*/
    return 0;
}
