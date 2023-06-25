#include <bits/stdc++.h>
using namespace std;

int n, t;
vector<pair<int, int>> adj[5002];
queue<int> q;

void solve() {
  int dist[5002];
  bool vis[5002];
  memset(dist, 0x7f, sizeof(dist));
  memset(vis, 0, sizeof(vis));

  int k, v; cin >> k >> v;
  dist[v] = 0x7f7f7f7f; vis[v] = 1;
  q.push(v);
  while (!q.empty()) {
    int cur = q.front(); q.pop();
    for (auto [co, nxt] : adj[cur]) {
      if (vis[nxt]) continue;
      dist[nxt] = min(dist[cur], co);
      vis[nxt] = 1; q.push(nxt);
    }
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (i == v) continue;
    if (dist[i] < k) continue;
    cnt++;
  }
  cout << cnt << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> t;
  for (int i = 1; i < n; i++) {
    int u, v, co;
    cin >> u >> v >> co;
    adj[u].push_back({co, v});
    adj[v].push_back({co, u});
  }
  while (t--) solve();
}