#include <bits/stdc++.h>
using namespace std;

int n, a, b, l, cnt, sum, mx;
pair<int, int> ans;
vector<int> v;

int main(){
  while(~scanf("%d", &n) and n and ++cnt){
    v.clear();
    while(n--){
      scanf("%d%d", &a, &b);
      v.push_back(a - b);
    }
    l = sum = mx = 0;
    for(int i = 0; i < v.size(); i++){
      sum += v[i];
      if(sum < 0) sum = 0, l = i+1;
      if(sum >= mx) mx = sum, ans = {l, i};
    }
    printf("Teste %d\n", cnt);
    if(mx) printf("%d %d\n\n", ans.first+1, ans.second+1);
    else printf("nenhum\n\n");
  }
}
