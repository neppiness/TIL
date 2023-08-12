#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m, st, en;
ll dist[10'002];
bool is_crit_path[100'002];

vector<tuple<int, int, int>> adj[100'002];
vector<tuple<int, int, int>> rev_adj[100'002];

priority_queue<pair<int, int>> pq; // 최대 힙 선언
queue<int> q;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v, co;
    cin >> u >> v >> co;
    adj[u].push_back({co, v, i});
    rev_adj[v].push_back({co, u, i});
  }
  cin >> st >> en;

  pq.push({0, st});
  while (!pq.empty()) {
    auto [co, cur] = pq.top(); pq.pop();
    if (dist[cur] != co) continue;
    for (auto [dco, nxt, id] : adj[cur]) {
      dco += co;
      if (dist[nxt] >= dco) continue;
      dist[nxt] = dco;
      pq.push({dco, nxt});
    }
  }

  q.push(en);
  while (!q.empty()) {
    int cur = q.front(); q.pop();
    for (auto [dco, nxt, id] : rev_adj[cur]) {
      if (is_crit_path[id]) continue;
      int d = dist[cur] - dco;
      if (dist[nxt] != d) continue;
      is_crit_path[id] = 1;
      q.push(nxt);
    }
  }

  int cnt = 0;
  for (int i = 0; i < m; i++)  
    cnt += is_crit_path[i];
  cout << dist[en] << '\n' << cnt;
}