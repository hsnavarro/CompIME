#include <bits/stdc++.h>
using namespace std;

int n;
vector<double> notas;

double Calc(vector<double> &a){
    double s = 0;
    for(auto x : a) s += x;
    return s/a.size();
}

int main(){
    cout << "Entre com o n: " << endl;
    cin >> n;
    double a;
    while(n--) cin >> a, notas.push_back(a);
    cout << fixed << setprecision(2) << Calc(notas) << endl;
}