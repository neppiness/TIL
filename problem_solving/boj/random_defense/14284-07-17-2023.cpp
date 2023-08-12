#include <bits/stdc++.h>
using namespace std;

priority_queue< pair<int, int>, 
    vector<pair<int, int>>,
    greater<pair<int, int>> > pq;

int n, m, st, en, dist[5002];
vector<pair<int, int>> adj[5002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(dist, 0x7f, sizeof(dist));

  cin >> n >> m;
  while (m--) {
    int u, v, co;
    cin >> u >> v >> co;
    adj[u].push_back({co, v});
    adj[v].push_back({co, u});
  }
  cin >> st >> en;
  pq.push({0, st});
  dist[st] = 0;

  while (!pq.empty()) {
    auto [co, cur] = pq.top(); pq.pop();
    if (dist[cur] != co) continue;
    for (auto [dco, nxt] : adj[cur]) {
      dco += co;
      if (dco >= dist[nxt]) continue;
      pq.push({dco, nxt});
      dist[nxt] = dco;
    }
  }
  cout << dist[en];
}