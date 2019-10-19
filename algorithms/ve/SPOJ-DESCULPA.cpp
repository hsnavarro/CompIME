#include <bits/stdc++.h>
using namespace std;

int n, w, cnt, dp[55][1005];
int p[55], v[55];

int main(){
  while(~scanf("%d%d", &w, &n) and w and n and ++cnt){
    for(int i = 0; i < n; i++) scanf("%d%d", &p[i], &v[i]);

    for(int i = 0; i <= n; i++)
      for(int k = 0; k <= w; k++) dp[i][k] = 0;

    for(int i = 0; i < n; i++)
      for(int k = 0; k <= w; k++){
        dp[i+1][k] = dp[i][k];
        if(k - p[i] >= 0) dp[i+1][k] = max(dp[i+1][k], dp[i][k-p[i]] + v[i]);
      }

    printf("Teste %d\n", cnt);
    printf("%d\n\n", dp[n][w]);
  }
}
