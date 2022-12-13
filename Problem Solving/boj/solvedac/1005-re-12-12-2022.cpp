#include <bits/stdc++.h>
using namespace std;

int solve() {
  int n, k;
  cin >> n >> k;

  int dist[1002] = {};
  int ind[1002] = {};
  vector<pair<int, int>> adj[1002]; // adj[u] -> {cost, v}

  for(int i = 1; i <= n; i++)
    cin >> dist[i];

  while(k--) {
    int u, v; cin >> u >> v;
    adj[v].push_back({dist[u], u}); // 방향을 역전시켜 v -> u로 받음
    ind[u]++;
  }

  int w; cin >> w;
  adj[n + 1].push_back({dist[w], w});
  ind[w] = 1;
  
  fill(dist, dist + n + 2, 0);

  queue<int> q;
  q.push(n + 1);

  int ans = 0;
  while(!q.empty()) {
    int cur = q.front(); q.pop();
    for(auto [cost, nxt] : adj[cur]) {
      dist[nxt] = max(dist[nxt], dist[cur] + cost);
      ind[nxt]--;
      if(ind[nxt] == 0) q.push(nxt);
      ans = max(dist[nxt], ans);
    }
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--)
    cout << solve() << '\n';
}