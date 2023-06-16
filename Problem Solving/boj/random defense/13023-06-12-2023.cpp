#include <bits/stdc++.h>
using namespace std;

int n, m;
bool is_edge_used[2002];
int dist[2002];

vector<pair<int, int>> adj[2002]; // adj[cur] = {nxt, id};
queue<tuple<int, int, int>> q; // q = {dist, nxt, id};

bool solve(int st) {
  memset(is_edge_used, 0, sizeof(is_edge_used));
  memset(dist, 0, sizeof(dist));

  q.push({0, st, m});
  while (!q.empty()) {
    auto [co, cur, cid] = q.front(); q.pop();
    if (dist[cur] != co) continue;
    is_edge_used[cid] = 1;
    for (auto [nxt, nid] : adj[cur]) {
      if (is_edge_used[nid]) continue;
      int d = dist[cur] + 1;
      if (d <= dist[nxt]) continue;
      dist[nxt] = d;
      q.push({d, nxt, nid});
    }
  }

  for (int i = 0; i < n; i++)
    if(dist[i] >= 4) return 1;
  return 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back({v, i});
    adj[v].push_back({u, i});
  }

  for (int i = 0; i < n; i++) {
    if (!solve(i)) continue;
    cout << 1; return 0;
  }
  cout << 0;
}