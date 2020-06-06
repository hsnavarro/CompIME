#include <bits/stdc++.h>
using namespace std;

const int N = 105;
vector<int> adj[N];
int n, t, a, size, ans, value, num, vis[N];

void dfs(int x){
  vis[x] = num;
  for(auto u : adj[x]) if(vis[u] != num) dfs(u), size++;
  if(size > value) value = size, ans = x;
}

void reset(){
  for(int i = 0; i < N; i++) adj[i].clear();
  memset(vis, 0, sizeof vis);
  size = 0, ans = N, value = 0, num = 1;
}

int main(){
  while(~scanf("%d", &n) and n){
    reset();
    for(int i = 1; i <= n; i++){
      scanf("%d", &t);
      while(t--) scanf("%d", &a), adj[i].push_back(a);
    }
    for(int i = 1; i <= n; i++) dfs(i), num++, size = 0;
    printf("%d\n", ans);
  }
}
