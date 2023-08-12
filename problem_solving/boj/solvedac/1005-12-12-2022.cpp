#include <bits/stdc++.h>
using namespace std;

int solve() {
  int n, k, mx = 0;
  cin >> n >> k;

  vector<pair<int, int>> adj[n + 2]; // adj[u] -> {cost, v}

  int dist[n + 2]; // 정점 u 건설 기간
  for(int i = 1; i <= n; i++)
    cin >> dist[i];

  while(k--) {
    int u, v;
    cin >> u >> v;
    adj[v].push_back({dist[u], u}); // 그래프 방향을 역으로 받음
  }

  int w; cin >> w;
  adj[n + 1].push_back({dist[w], w});

  fill(dist, dist + n + 2, 0); // 여기서부터 dist를 리셋하고 거리 기록 테이블로 활용

  // dijkstra's algo.
  priority_queue< pair<int, int> > pq; // pair {dist, u}
  pq.push({0, n + 1});

  while(!pq.empty()) {
    auto [w, u] = pq.top(); pq.pop();
    if(w != dist[u]) continue;
    for(auto [dw, v] : adj[u]) {
      dw += w;
      if(dw <= dist[v]) continue;
      dist[v] = dw;
      pq.push({dw, v});
      mx = max(mx, dw);
    }
  }
  return mx;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--)
    cout << solve() << '\n';
}