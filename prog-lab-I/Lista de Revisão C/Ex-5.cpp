#include <bits/stdc++.h>
using namespace std;

int n;

int fib(int i){
    if(i == 0) return 0;
    if(i == 1) return 1;
    else return fib(i-1) + fib(i-2);
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cout << "Entre com o numero: ";
    cout.flush();
    cin >> n;
    cout << fib(n) << endl;
}