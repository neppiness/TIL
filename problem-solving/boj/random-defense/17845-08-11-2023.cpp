#include <bits/stdc++.h>
using namespace std;

const int INF = 1'111'111;
int n, m, st, en;

int k[100'002];
priority_queue<pair<int, int>> pq;
vector<pair<int, int>> adj[100'002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> st >> en;
  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({w, v});
    adj[v].push_back({w, u});
  }
  k[st] = INF;
  pq.push({INF, st});
  while (!pq.empty()) {
    auto [w, u] = pq.top(); pq.pop();
    if (k[u] != w) continue;
    for (auto [dw, v] : adj[u]) {
      dw = min(dw, w);
      if (k[v] >= dw) continue;
      k[v] = dw;
      pq.push({dw, v});
    }
  }
  cout << k[en];
}