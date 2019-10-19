#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int n, m, l, k, x; 
multiset<int> h;

int go(int x, int y, multiset<int> s){
  int h = 0, sum = 0;
  while(h < y and s.size()){
    int top = - (*(s.begin()));
    s.erase(s.begin());
    if(top == x) sum++, h += l;
    else if(s.count(top - x)) s.erase(s.find(top - x)), sum += 2, h += l;
  }
  return (h == y ? sum : INF);
}

int main(){
  while(~scanf("%d%d", &n, &m) and n and m){
    h.clear();
    scanf("%d", &l);
    scanf("%d", &k);
    while(k--) scanf("%d", &x), h.insert(-100*x);
    int ans = min(go(100*n, 100*m, h), go(100*m, 100*n, h));
    if(ans == INF) printf("impossivel\n");
    else printf("%d\n", ans);
  }
}
