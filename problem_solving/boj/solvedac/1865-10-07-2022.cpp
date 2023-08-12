#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int dist[502][502];

int n, m, w;
int u, v, c;

bool solve() {
  cin >> n >> m >> w;
  for(int i = 1; i <= n; i++) {
    fill(dist[i] + 1, dist[i] + n + 1, INF);
    dist[i][i] = 0;
  }
  while(m--) {
    cin >> u >> v >> c;
    dist[u][v] = min(c, dist[u][v]);
    dist[v][u] = min(c, dist[v][u]);
  }
  while(w--) {
    cin >> u >> v >> c;
    dist[u][v] = -c;
  }
  for(int k = 1; k <= n; k++)
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= n; j++)
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
  
  for(int i = 1; i <= n; i++)
    if(dist[i][i] < 0) return 1;

  return 0;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--) {
    if(solve()) cout << "YES" << '\n';
    else cout << "NO" << '\n';
  }
}