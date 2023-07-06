#include <bits/stdc++.h>
using namespace std;

int n, k, m;
int dist[100'002];
set<int> adj[100'002];
queue<int> q;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(dist, -1, sizeof(dist));

  cin >> n >> k >> m;
  while (m--) {
    int u; cin >> u;
    for (int i = 0; i < k - 1; i++) {
      int v; cin >> v;
      adj[u].insert(v);
      adj[v].insert(u);
      swap(u, v);
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << i << ": ";
    for (int j : adj[i]) cout << j << ' ';
    cout << '\n';
  }

  dist[1] = 1; q.push(1);
  while (!q.empty()) {
    int cur = q.front(); q.pop();
    for (int nxt : adj[cur]) {
      if (dist[nxt] != -1) continue;
      q.push(nxt);
      dist[nxt] = dist[cur] + 1;
    }
  }

  int ans = dist[n];
  cout << ans;
}