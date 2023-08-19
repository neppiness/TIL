#include <bits/stdc++.h>
using namespace std;

void solve() {
  int dist[102][102];
  memset(dist, 0x3f, sizeof(dist));

  int n, m; cin >> n >> m;
  for (int i = 1; i <= n; i++)
    dist[i][i] = 0;
  
  while (m--) {
    int u, v, c;
    cin >> u >> v >> c;
    dist[u][v] = c;
    dist[v][u] = c;
  }
  vector<int> p;
  cin >> m;
  while (m--) {
    int x; cin >> x;
    p.push_back(x);
  } 
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);

  int tot = 0x7f7f7f7f;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int tmp = 0;
    for (int f : p) tmp += dist[f][i];
    if (tot <= tmp) continue;
    tot = tmp;
    ans = i;
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int t; cin >> t;
  while(t--) solve();
}
