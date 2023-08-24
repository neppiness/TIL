#include <bits/stdc++.h>
using namespace std;

int dist[302][302]; // dist[cur][no of visited city];
vector<pair<int, int>> adj[302]; // adj[cur] = {po, nxt};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n, k, m;
  cin >> n >> k >> m;

  while (m--) {
    int u, v, po;
    cin >> u >> v >> po;
    if (u > v) continue;
    adj[u].push_back({po, v});
  }

  priority_queue<tuple<int, int, int>> pq; // pq = {tot, v, no of visited};
  pq.push({0, 1, 1});
  while (!pq.empty()) {
    auto [tot, u, no] = pq.top(); pq.pop();
    if (dist[u][no] != tot) continue;
    for (auto [po, v] : adj[u]) {
      po += tot;
      if (dist[v][no + 1] >= po) continue;
      dist[v][no + 1] = po;
      pq.push({po, v, no + 1});
    }
  }

  int ans = 0;
  for (int i = 2; i <= k; i++)
    ans = max(dist[n][i], ans);
  cout << ans;
}
