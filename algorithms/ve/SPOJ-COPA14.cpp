#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second

typedef pair<int, int> pii;
typedef pair<int, pii> piii;

const int N = 100 + 5;

int n, f, r, cost, a, b, w, sz[N], par[N];
vector<piii> fer, rod;

int find(int a) { return par[a] == a ? a : par[a] = find(par[a]); }

void unite(int a, int b, int w){
  if((a = find(a)) == (b = find(b))) return;
  cost += w;
  if(sz[a] < sz[b]) swap(a, b);
  par[b] = a, sz[a] += sz[b];
}

int main(){
  scanf("%d%d%d", &n, &f, &r);
  for(int i = 1; i <= n; i++) sz[i] = 1, par[i] = i;
  while(f--){
    scanf("%d%d%d", &a, &b, &w);
    fer.push_back(make_pair(w, make_pair(a, b)));
  }
  while(r--){
    scanf("%d%d%d", &a, &b, &w);
    rod.push_back(make_pair(w, make_pair(a, b)));
  }

  sort(fer.begin(), fer.end());
  sort(rod.begin(), rod.end());

  for(int i = 0; i < fer.size(); i++) unite(fer[i].nd.st, fer[i].nd.nd, fer[i].st);
  for(int i = 0; i < rod.size(); i++) unite(rod[i].nd.st, rod[i].nd.nd, rod[i].st);
  
  printf("%d\n", cost);
}
