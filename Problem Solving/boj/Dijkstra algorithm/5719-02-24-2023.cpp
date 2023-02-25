#include <bits/stdc++.h>
using namespace std;

const int INF = 0x7f7f7f7f;
const int EMX = 10'000 + 2;
const int NMX = 500 + 2;

int n, m, st, en;
bool is_opt[EMX]; // is_opt[edge_id]
int dist[NMX];
vector<tuple<int, int, int>> adj[NMX]; // v[u] = {cost, v, id}

void setup() {
  cin >> st >> en;
  for(int i = 0; i < n; i++) adj[i].clear();
  fill(is_opt, is_opt + EMX, 0);
  fill(dist, dist + NMX, INF);
  for(int i = 0; i < m; i++) {
    int u, v, cost;
    cin >> u >> v >> cost;
    adj[u].push_back({cost, v, i});
  }
}

void solve() {
  priority_queue< tuple<int, int, int>,
      vector<tuple<int, int, int>>,
      greater<tuple<int, int, int>> > pq; // {cost, v, id};

  // 최단 경로 계산 및 사용된 간선 기록
  dist[st] = 0;
  pq.push({0, st, -1});

  while(!pq.empty()) {
    auto [co, u, cid] = pq.top(); pq.pop();
    if(co != dist[u]) continue;
    if(cid != -1) is_opt[cid] = 1;
    for(auto [dco, v, nid] : adj[u]) {
      dco += co;
      if(dco >= dist[v]) continue;
      dist[v] = dco;
      pq.push({dco, v, nid});
    }
  }

  for(int i = 0; i < n; i++)
    cout << dist[i] << ' ';
  cout << '\n';

  fill(dist, dist + NMX, INF);

  // 거의 최단 경로 계산하기
  dist[st] = 0;
  pq.push({0, st, -1});
  while(!pq.empty()) {
    auto [co, u, cid] = pq.top(); pq.pop();
    if(co != dist[u]) continue;
    for(auto [dco, v, nid] : adj[u]) {
      if(is_opt[nid]) continue;
      dco += co;
      if(dco >= dist[v]) continue;
      dist[v] = dco;
      pq.push({dco, v, nid});
    }
  }

  if(dist[en] == INF) cout << -1 << '\n';
  else cout << dist[en] << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  while(n != 0 && m != 0) {
    setup();
    solve();
    cin >> n >> m;
  }
}