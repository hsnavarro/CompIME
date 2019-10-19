#include <bits/stdc++.h>
using namespace std;

const int N = 100 + 5;
const int INF = 0x3f3f3f3f;

int n, m, u, v, w, c, cnt;
int dp[N][N][N];

int main(){
  while(~scanf("%d%d", &n, &m) and ++cnt){
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= n; j++)
        for(int k = 0; k <= n; k++)
          dp[i][j][k] = (i == j ? 0 : INF);


    for(int i = 0; i < m; i++){
      scanf("%d%d%d", &u, &v, &w);
      for(int k = 0; k <= n; k++) dp[u][v][k] = min(dp[u][v][k], w);
    }

    for(int k = 1; k <= n; k++)
      for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) 
          dp[i][j][k] = min(dp[i][j][k-1], dp[i][k][k-1] + dp[k][j][k-1]);

    scanf("%d", &c);
    printf("Instancia %d\n", cnt);
    while(c--){
      scanf("%d%d%d", &u, &v, &w);
      printf("%d\n", dp[u][v][w]==INF ? -1 : dp[u][v][w]);
    }
    printf("\n");
  }
}
