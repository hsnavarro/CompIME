#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second

typedef pair<int, int> pii;
typedef pair<int, pii> piii;

const int N = 1e6+5;

int par[N], sz[N], cont, cost, a, b, w, n, m, n1, n2;
vector<piii> edges, res;

int find (int a) { return par[a] == a ? a : par[a] = find(par[a]); }
void unite (int a, int b) {
    if ((a = find(a)) == (b = find(b))) return;
    if (sz[a] < sz[b]) swap(a, b);
    par[b] = a; sz[a] += sz[b];
}
int main () {
  while(~scanf("%d%d", &n, &m) and n) {
    for (int i = 0; i <= n; i++) par[i] = i, sz[i] = 1;
    cost = 0, edges.clear(), res.clear();

    for (int i = 0; i < m; i++) {
      scanf("%d%d%d", &a, &b, &w);
      edges.push_back({w, {a, b}});
    }

    sort(edges.begin(), edges.end());
    for (auto e : edges) if (find(e.nd.st) != find(e.nd.nd)) {
      unite(e.nd.st, e.nd.nd), cost += e.st;
      res.push_back({e.st, {e.nd.st, e.nd.nd}});
    }

    printf("Teste %d\n", ++cont);
    for (int i = 0; i < res.size(); i++) {
      n1 = max(res[i].nd.st, res[i].nd.nd);
      n2 = min(res[i].nd.st, res[i].nd.nd);
      printf("%d %d\n", n2, n1);
    }
    printf("\n");
  }
}
