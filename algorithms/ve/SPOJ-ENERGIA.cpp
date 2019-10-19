#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, cnt, vis[105];
vector<int> adj[105];

void dfs(int x = 1){
  vis[x] = 1;
  for(auto u : adj[x]) if(!vis[u]) dfs(u);
}

int main(){
  while(~scanf("%d%d", &n, &m) and n and m and ++cnt){
    for(int i = 1; i <= n; i++) vis[i] = 0, adj[i].clear();
    while(m--){
      scanf("%d%d", &a, &b);
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    printf("Teste %d\n", cnt);
    dfs();
    int cond = 1;
    for(int i = 1; i <= n; i++) if(!vis[i]) cond = 0;
    printf("%s\n\n", (cond ? "normal" : "falha"));
  }
}
