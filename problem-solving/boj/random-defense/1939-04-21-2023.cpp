#include <bits/stdc++.h>
using namespace std;

const int MX = 10'000;
const int INF = 0x7f7f7f7f;

int mx[MX + 2];
vector<pair<int, int>> adj[MX + 2]; // adj[cur] = {lim, nxt}
priority_queue<pair<int, int>> pq; // 최대 힙 선언, {lim, cur}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  while(m--) {
    int u, v, lim;
    cin >> u >> v >> lim;
    adj[u].push_back({lim, v});
    adj[v].push_back({lim, u});
  }

  int st, en; cin >> st >> en;
  mx[st] = INF;
  pq.push({INF, st});
  while(!pq.empty()) {
    auto [clim, cur] = pq.top(); pq.pop();
    if(clim != mx[cur]) continue;
    for(auto [nlim, nxt] : adj[cur]) {
      nlim = min(clim, nlim);
      if(nlim <= mx[nxt]) continue;
      mx[nxt] = nlim;
      pq.push({nlim, nxt});
    }
  }
  cout << mx[en];
}