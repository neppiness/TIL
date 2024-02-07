#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 0x7f7f7f7f7f7f7f7f;

int n, m;
priority_queue<pair<ll, int>,
    vector<pair<ll, int>>,
    greater<pair<ll, int>> > pq;
vector<pair<ll, int>> adj[100'002];

ll dist[100'002];
bool is_visible[100'002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(dist, 0x7f, sizeof(dist)); 

  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> is_visible[i];
  is_visible[n - 1] = 0;

  while (m--) {
    int u, v; ll co;
    cin >> u >> v >> co;
    if (is_visible[u] || is_visible[v]) continue;
    adj[u].push_back({co, v});
    adj[v].push_back({co, u});
  }

  dist[0] = 0;
  pq.push({0, 0});

  while (!pq.empty()) {
    auto [co, cur] = pq.top(); pq.pop();
    if (dist[cur] != co) continue;
    for (auto [dco, nxt] : adj[cur]) {
      dco += co;
      if (dco >= dist[nxt]) continue;
      dist[nxt] = dco;
      pq.push({dco, nxt});
    }
  }
  if (dist[n - 1] == INF) dist[n - 1] = -1;
  cout << dist[n - 1];
}
