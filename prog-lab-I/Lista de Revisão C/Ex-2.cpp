#include <bits/stdc++.h>
using namespace std;

int n;

void print(int i){
    if(i == n) { cout << endl; return; }
    cout << i << " ";
    print(i + 2);
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    print(2);
}