#include <bits/stdc++.h>
using namespace std;

int n;
double *notes;

double calc(int n, double *notes){
    double sum = 0;
    for(int i = 0; i < n; i++) sum += notes[i];
    return sum/n;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cout << "Entre com a quantidade: " << endl;
    cin >> n;
    notes = (double*) malloc(n*sizeof(double));
    for(int i = 0; i < n; i++) cin >> notes[i];
    cout << calc(n, notes) << endl;
    free(notes);
    return 0;
}