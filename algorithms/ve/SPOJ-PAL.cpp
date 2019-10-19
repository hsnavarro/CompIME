#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 2000 + 5;

int n, cnt, p[N][N], dist[N];
string s;
queue<pair<int, int>> q;

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  while(cin >> n and n and ++cnt){
    cin >> s;
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++) p[i][j] = (i == j) ? 1 : 0;

    for(int i = 0; i < n; i++){
      int x = 0;
      while(i-x >= 0 and i+x+1 < n and s[i-x] == s[i+x+1]) p[i-x][i+x+1] = 1, x++;
      x = 0;
      while(i-x-1 >= 0 and i+x+1 < n and s[i-x-1] == s[i+x+1]) p[i-x-1][i+x+1] = 1, x++; 
    }

    for(int i = 0; i <= n; i++) dist[i] = INF; 
    dist[0] = 0;
    q.push({0, 0});
    while(q.size()){
      int x = q.front().first;
      int h = q.front().second;
      q.pop();
      for(int i = x; i < n; i++){
        if(!p[x][i]) continue;
        if(dist[i+1] != INF) continue;
        dist[i+1] = h + 1;
        q.push({i+1, dist[i+1]});
      }
    }
    cout << "Teste " << cnt << "\n" << dist[n] << "\n\n"; 
  }
}
