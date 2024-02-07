#include <bits/stdc++.h>
using namespace std;

const int INF = 0x7f7f7f7f;

vector<pair<int, int>> adj[20'002]; // adj[u] = {cost, v};
int dist[20'002];
priority_queue<pair<int, int>,
    vector<pair<int, int>>,
    greater<pair<int, int>> > pq; // pq : {dist, u};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(dist, 0x7f, sizeof(dist));

  int n, e; cin >> n >> e;
  int st; cin >> st;
  dist[st] = 0;

  while (e--) {
    int u, v, w; cin >> u >> v >> w;
    adj[u].push_back({w, v});
  }

  pq.push({0, st});
  while (!pq.empty()) {
    auto [co, cur] = pq.top(); pq.pop();
    if (dist[cur] != co) continue;
    for (auto [dco, nxt] : adj[cur]) {
      dco += co;
      if (dist[nxt] <= dco) continue;
      dist[nxt] = dco;
      pq.push({dco, nxt});
    }
  }
  for (int i = 1; i <= n; i++) {
    if (dist[i] == INF) cout << "INF\n";
    else cout << dist[i] << '\n';
  }
}
