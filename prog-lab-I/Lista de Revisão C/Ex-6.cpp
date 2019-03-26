#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> fib;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cout << "Entre com o numero: ";
    cout.flush();
    cin >> n;
    fib.push_back(0);
    fib.push_back(1);
    for(int i = 2; i <= n; i++) fib.push_back(fib[i-1] + fib[i-2]);
    cout << fib[n] << endl;
}