#include <bits/stdc++.h>
using namespace std;

#define pb push_back

const int INF = 0x3f3f3f3f;

int n, cnt;
string a;
map<string, int> ht;
map<string, vector<string>> adj;
vector<string> in;

bool cmp(string a, string b){
  if(a.substr(3) == b.substr(3)) return a[0] < b[0];
  return a.substr(3) < b.substr(3);
}

void take_input(string a){
  string name;
  vector<string> aux;
  for(int i = 0; i < a.size(); i++){
    if(a[i] == ',') aux.pb(name), in.pb(name), name = "", i++;
    else if(i == a.size() - 1) aux.pb(name), in.pb(name);
    else name += a[i];
  }

  for(auto x : aux)
    for(auto y : aux) if(x != y) adj[x].pb(y);
}

void bfs(string s = "P. Erdos"){
  queue<pair<string, int>> q;
  q.push({s, 0});
  while(q.size()){
    string x = q.front().first;
    int h = q.front().second;
    q.pop();
    for(auto u : adj[x]) {
      if(ht[u] != INF) continue;
      ht[u] = h + 1;
      q.push({u, ht[u]});
    }
  }
}

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  while(cin >> n and n and ++cnt){
    ht.clear(), adj.clear(), in.clear(); 
    cin.ignore();
    
    while(n--) getline(cin, a), take_input(a);
    
    cout << "Teste " << cnt << "\n";
    sort(in.begin(), in.end(), cmp);
    in.resize(unique(in.begin(), in.end()) - in.begin());
    
    for(auto x : in) ht[x] = INF;
    ht["P. Erdos"] = 0;
    bfs();
    
    for(auto x : in) {
      if(x == "P. Erdos") continue;
      if(ht[x] != INF) cout << x << ": " << ht[x] << "\n";
      else cout << x << ": infinito\n"; 
    }
    cout << "\n";
  }
}
