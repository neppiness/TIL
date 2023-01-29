#include <bits/stdc++.h>
using namespace std;

const int MX = 300;
const int INF = 0x3f3f3f3f;

int h[MX + 2][MX + 2];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m, t;
  cin >> n >> m >> t;

  for(int i = 1; i <= n; i++)
    fill(h[i], h[i] + MX + 1, INF);

  while(m--) {
    int u, v, height; 
    cin >> u >> v >> height;
    h[u][v] = height;
  }

  for(int k = 1; k <= n; k++)
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= n; j++)
        h[i][j] = min(h[i][j], max(h[i][k], h[k][j]));

  while(t--) {
    int st, en;
    cin >> st >> en;
    if(h[st][en] == INF) cout << -1 << '\n';
    else cout << h[st][en] << '\n';
  }
}