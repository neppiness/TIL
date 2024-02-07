#include <bits/stdc++.h>
using namespace std;

int n, m;
int dist[102][102];

bool solve() {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (dist[i][j] > 6) return 0;
  return 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(dist, 0x3f, sizeof(dist));

  cin >> n >> m;
  while (m--) {
    int u, v; cin >> u >> v;
    u--; v--;
    dist[u][v] = 1;
    dist[v][u] = 1;
  }
  
  for (int k = 0; k < n; k++)
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

  if (solve()) cout << "Small World!";
  else cout << "Big World!";
}
