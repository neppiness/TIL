#include <bits/stdc++.h>
using namespace std;

const int kInf = 0x7f7f7f7f;

int n, m, st, en;
bool is_opt_path[10002];
int dist[502];

 //adj[cur], rev_adj[cur] = {cost, nxt, id};
vector<tuple<int, int, int>> adj[502];
vector<tuple<int, int, int>> rev_adj[502];

priority_queue< pair<int, int>,
    vector<pair<int, int>>,
    greater<pair<int, int>> > pq;

queue<int> q;

void setup() {
  for (int i = 0; i < n; i++) {
    adj[i].clear(); rev_adj[i].clear();
  }
  fill(is_opt_path, is_opt_path + m, 0);

  cin >> st >> en;
  for (int id = 0; id < m; id++) {
    int u, v, cost;
    cin >> u >> v >> cost;
    adj[u].push_back({cost, v, id});
    rev_adj[v].push_back({cost, u, id});
  }
}

void solve() {
  fill(dist, dist + n, kInf);
  dist[st] = 0;
  pq.push({0, st});
  while (!pq.empty()) {
    auto [co, cur] = pq.top(); pq.pop();
    if (dist[cur] != co) continue;
    for (auto [dco, nxt, id] : adj[cur]) {
      if (is_opt_path[id]) continue;
      dco += co;
      if (dist[nxt] <= dco) continue;
      dist[nxt] = dco;
      pq.push({dco, nxt});
    }
  }
}

void trace() {
  q.push(en);
  while (!q.empty()) {
    int cur = q.front(); q.pop();
    for (auto [dco, nxt, id] : rev_adj[cur]) {
      if (is_opt_path[id]) continue;
      int d = dist[cur] - dco;
      if (dist[nxt] != d) continue;
      q.push(nxt);
      is_opt_path[id] = 1;
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  while (n != 0 || m != 0) {
    setup();
    solve();
    trace();
    solve();

    if (dist[en] == kInf) dist[en] = -1;
    cout << dist[en] << '\n';
    cin >> n >> m;
  }
}
/*
pq는 모든 값이 빠질 때까지 다익스트라를 돌리기 때문에 초기화를 따로 하지 않는다.
*/