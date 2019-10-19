#include <bits/stdc++.h>
using namespace std;

int n, a, sum;
char c;
int cont[65][2];

int main(){
  while(~scanf("%d", &n)){
    sum = 0;
    memset(cont, 0, sizeof(cont));
    while(n--){
      scanf("%d %c", &a, &c);
      cont[a][c == 'D' ? 1 : 0]++;
    }
    for(int i = 0; i < 65; i++) sum += min(cont[i][0], cont[i][1]);
    printf("%d\n", sum);
  }
}
