#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> adj[50002]; // adj[cur] = {co, nxt}
int dist[50002], n, m;

priority_queue< pair<int, int>,
    vector<pair<int, int>>,
    greater<pair<int, int>> > pq;

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

  pq.push({0, 1});
  dist[1] = 0;

  while (!pq.empty()) {
    auto [co, cur] = pq.top(); pq.pop();
    if (co != dist[cur]) continue;
    for (auto [dco, nxt] : adj[cur]) {
      dco += co;
      if (dist[nxt] <= dco) continue;
      dist[nxt] = dco;
      pq.push({dco, nxt});
    }
  }
  cout << dist[n];
}