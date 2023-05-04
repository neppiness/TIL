#include <bits/stdc++.h>
using namespace std;

const int MX = 400;
const int INF = 0x3f3f3f3f;

int n, k, s;
int p_dist[MX + 2][MX + 2], n_dist[MX + 2][MX + 2];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(p_dist, 0x3f, sizeof(p_dist));
  memset(n_dist, 0x3f, sizeof(n_dist));

  for(int i = 0; i <= MX; i++) {
    p_dist[i][i] = 0;
    n_dist[i][i] = 0;
  }

  cin >> n >> k;
  while(k--) {
    int u, v; cin >> u >> v;
    p_dist[v][u] = 1; // v -> u는 시간의 역순 관계이다.
    n_dist[u][v] = 1; // u -> v는 시간순 관계이다.
  }

  for(int k = 1; k <= n; k++)
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= n; j++) {
        p_dist[i][j] = min(p_dist[i][j], p_dist[i][k] + p_dist[k][j]);
        n_dist[i][j] = min(n_dist[i][j], n_dist[i][k] + n_dist[k][j]);
      }

  cin >> s;
  while(s--) {
    int u, v; cin >> u >> v;
    if (p_dist[u][v] < INF) cout << 1;
    else if (n_dist[u][v] < INF) cout << -1;
    else cout << 0;
    cout << '\n';
  }
}