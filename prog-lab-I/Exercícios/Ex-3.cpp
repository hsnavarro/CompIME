#include <bits/stdc++.h>
using namespace std;

string s, aux;

int main(){
    ifstream file1("file.txt");
    ofstream file2("file.txt");
    cout << "Passe uma palavra: " << endl;
    cin >> s;
    file2 << s << endl;
    file1 >> aux;
    if(s == aux) cout << "Sua palavra: " << s << endl;
    else cout << "Erro na escrita/leitura" << endl;
}