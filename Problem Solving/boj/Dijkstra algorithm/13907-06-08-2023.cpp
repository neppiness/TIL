#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll kInf = 0x7f7f7f7f7f7f;

int n, m, k, st, en;
ll dist[1002][1002];
int inc[30002];

priority_queue< tuple<ll, int, int>,
    vector<tuple<ll, int, int>>,
    greater<tuple<ll, int, int>> > pq;

vector<pair<int, int>> adj[1002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 0; i <= 1000; i++)
    fill(dist[i], dist[i] + 1001, kInf);

  cin >> n >> m >> k;
  cin >> st >> en;

  while (m--) {
    int u, v, co;
    cin >> u >> v >> co;
    adj[u].push_back({co, v});
    adj[v].push_back({co, u});
  }

  for (int i = 1; i <= k; i++)
    cin >> inc[i];

  dist[0][st] = 0;
  // pq : {cost, nop, cur}, nop: no of paths pass through
  pq.push({0, 0, st});
  while (!pq.empty()) {
    auto [co, nop, cur] = pq.top(); pq.pop();
    if (dist[nop][cur] != co) continue;
    if (nop == n) continue;
    for (auto [dco, nxt] : adj[cur]) {
      dco += co;
      if (dco >= dist[nop + 1][nxt]) continue;
      dist[nop + 1][nxt] = dco;
      pq.push({dco, nop + 1, nxt});
    }
  }

  for (int i = 0; i <= k; i++) {
    ll ans = kInf;
    for (int nop = 0; nop <= n; nop++) {
      dist[nop][en] += inc[i]*nop;
      ans = min(ans, dist[nop][en]);
    }
    cout << ans << '\n';
  }
}