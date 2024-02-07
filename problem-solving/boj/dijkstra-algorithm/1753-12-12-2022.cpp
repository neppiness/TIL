#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MX = 20'002;

int dist[MX];
vector<pair<int, int>> adj[MX]; // [u] -> {cost, v}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int v, e, k;
  cin >> v >> e >> k;

  fill(dist, dist + v + 1, INF);
  dist[k] = 0;

  while(e--) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({w, v});
  }

  priority_queue< pair<int, int>,
      vector<pair<int, int>>,
      greater<pair<int, int>> > pq;

  pq.push({0, k});

  while(!pq.empty()) {
    auto [w, u] = pq.top(); pq.pop();
    if(dist[u] < w) continue; // 꺼냈는데 이미 더 작은 값으로 갱신이 된 상태면 스킵
    for(auto [dw, v] : adj[u]) {
      dw += w;
      if(dw < dist[v]) { // 새로운 경로가 현재 테이블에 저장된 거리보다 짧은 경우 처리
        pq.push({dw, v});
        dist[v] = dw;
      }
    }
  }

  for(int i = 1; i <= v; i++) {
    if(dist[i] == INF) cout << "INF" << '\n';
    else cout << dist[i] << '\n';
  }
}