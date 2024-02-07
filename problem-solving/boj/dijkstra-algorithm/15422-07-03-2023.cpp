#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m, f, st, en;
ll dist[2][50'002];

vector<tuple<ll, int, bool>> adj[50'002]; // adj[cur] = {cost, nxt, is_flight}
priority_queue< tuple<ll, int, bool>,
    vector<tuple<ll, int, bool>>,
    greater<tuple<ll, int, bool>> > pq; // pq = {cost, nxt, used_flight}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(dist, 0x3f, sizeof(dist));

  cin >> n >> m >> f >> st >> en;
  while (m--) {
    int u, v, c; cin >> u >> v >> c;
    adj[u].push_back({c, v, 0});
    adj[v].push_back({c, u, 0});
  }

  while (f--) {
    int u, v; cin >> u >> v;
    adj[u].push_back({0, v, 1});
  }

  dist[0][st] = 0;
  pq.push({0, st, 0});
  while (!pq.empty()) {
    auto [co, cur, used_fl] = pq.top(); pq.pop();
    if (dist[used_fl][cur] != co) continue;
    for (auto [dco, nxt, is_flight] : adj[cur]) {
      bool nxt_stat = used_fl | is_flight;
      dco += co;
      if (used_fl && is_flight) continue;
      if (dco >= dist[nxt_stat][nxt]) continue;
      dist[nxt_stat][nxt] = dco;
      pq.push({dco, nxt, nxt_stat});
    }
  }
  cout << min(dist[0][en], dist[1][en]);
}