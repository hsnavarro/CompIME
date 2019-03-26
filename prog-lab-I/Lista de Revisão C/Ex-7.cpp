#include <bits/stdc++.h>
using namespace std;

int n, a;
vector<int> v;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cout << "Entre com n: ";
    cout.flush();
    cin >> n;
    while(n--) cin >> a, v.push_back(a);
    sort(v.begin(), v.end());
    for(auto x : v) cout << x << " ";
    cout << endl;
}