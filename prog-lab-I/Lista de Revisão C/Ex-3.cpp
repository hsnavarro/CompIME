#include <bits/stdc++.h>
using namespace std;

int s, p = 1, a;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    ifstream cin("input.txt");
    while(cin >> a){
        if(a & 1) s += a;
        else p *= a;
    }
    cout << p << endl;
    cout << s << endl;
}