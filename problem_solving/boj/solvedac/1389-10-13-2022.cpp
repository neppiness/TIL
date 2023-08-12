#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int d[102][102];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  for(int i = 1; i <= n; i++) {
    fill(d[i] + 1, d[i] + n + 1, INF);
    d[i][i] = 0;
  }
  int u, v;
  while(m--) {
    cin >> u >> v;
    d[u][v] = 1;
    d[v][u] = 1;
  }

  for(int k = 1; k <= n; k++)
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= n; j++)
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

  int ans, sum;
  int min = INF;
  for(int i = 1; i <= n; i++) {
    sum = 0;
    for(int j = 1; j <= n; j++)
      sum += d[i][j];
    if(sum < min) {
      min = sum;
      ans = i;
    }
  }
  cout << ans;
}