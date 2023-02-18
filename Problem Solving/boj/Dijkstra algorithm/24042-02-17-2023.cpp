#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MX = 100'000 + 2;

int n, m; ll dist[MX];
vector<pair<int, int>> adj[MX];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(dist, 0x7f, sizeof(dist));

  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back({i, v});
    adj[v].push_back({i, u});
  }
  priority_queue< pair<ll, int>,
      vector<pair<ll, int>>,
      greater<pair<ll, int>> > pq;
  
  const int MOD = m;
  pq.push({0, 1});
  dist[1] = 0;
  while(!pq.empty()) {
    auto [cd, u] = pq.top(); pq.pop();
    if(dist[u] != cd) continue;
    for(auto [rmd, v] : adj[u]) {
      ll nd = (rmd + MOD - cd % MOD) % MOD;
      nd += cd + 1;
      if(nd >= dist[v]) continue;
      dist[v] = nd;
      pq.push({nd, v});
    }
  }
  cout << dist[n];
}