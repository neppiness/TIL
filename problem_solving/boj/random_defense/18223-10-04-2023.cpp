#include <bits/stdc++.h>
using namespace std;

int n, m, p;
vector<pair<int, int>> adj[5'002];

int dist[5'002];
priority_queue< pair<int, int>,
    vector<pair<int, int>>,
    greater<pair<int, int>> > pq;

int solve(int mid) {
  memset(dist, 0x7f, sizeof(dist));

  pq.push({0, mid});
  dist[mid] = 0;

  while (!pq.empty()) {
    auto [co, cur] = pq.top(); pq.pop();
    if (co > dist[cur]) continue;
    for (auto [dco, nxt] : adj[cur]) {
      dco += co;
      if (dco >= dist[nxt]) continue;
      dist[nxt] = dco;
      pq.push({dco, nxt});
    }
  }
  return dist[1] + dist[n];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> p;
  while (m--) {
    int u, v, co;
    cin >> u >> v >> co;
    adj[u].push_back({co, v});
    adj[v].push_back({co, u});
  }
  
  int d1 = solve(p);
  int d2 = solve(1);
  if (d1 == d2) cout << "SAVE HIM";
  else cout << "GOOD BYE";
}
