#include <bits/stdc++.h>
using namespace std;

const int MX = 300'000;

vector<int> ans;
int dist[MX + 2];
int n, m, k, x;

vector<pair<int, int>> adj[MX + 2]; // adj[u] = {cost, v};
priority_queue< pair<int, int>,
    vector<pair<int, int>>,
    greater<pair<int, int>> > pq; // {dist, v}

void solve() {
  pq.push({0, x});
  dist[x] = 0;

  while(!pq.empty()) {
    auto [co, u] = pq.top(); pq.pop();
    if(dist[u] != co) continue;
    for(auto [dco, v] : adj[u]) {
      dco += co;
      if(dist[v] < dco) continue;
      dist[v] = dco;
      pq.push({dco, v});
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(dist, 0x7f, sizeof(dist));

  cin >> n >> m >> k >> x;
  while(m--) {
    int u, v; cin >> u >> v;
    adj[u].push_back({1, v});
  }

  solve();

  for(int i = 1; i <= n; i++)
    if(dist[i] == k) ans.push_back(i);

  if(ans.size() == 0) cout << -1;
  else for(int a : ans) cout << a << '\n';
}