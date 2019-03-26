#include <bits/stdc++.h>
using namespace std;

double mm, mf;
int x, cm, cf;
char esc;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    ifstream cin("input.txt");
    while(cin >> esc >> x){
        if(esc == 'M') mm += x, cm++;
        else mf += x, cf++;
    }
    mm /= cm;
    mf /= cf;
    if(mm > mf) cout << "M " << mm << endl;
    else cout << "F " << mf << endl;
}