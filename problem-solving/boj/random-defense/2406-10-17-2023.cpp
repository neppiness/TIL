#include <bits/stdc++.h>
using namespace std;

int n, m;
int p[1002];

priority_queue< tuple<int, int, int>,
    vector<tuple<int, int, int>>,
    greater<tuple<int, int, int>> > pq;

int find(int u) {
  if (p[u] < 0) return u;
  return p[u] = find(p[u]);
}

bool try_merge(int u, int v) {
  u = find(u); v = find(v);
  if (u == v) return 0;
  if (p[u] > p[v]) swap(u, v);
  p[u] += p[v];
  p[v] = u;
  return 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(p, -1, sizeof(p));

  cin >> n >> m;
  while (m--) {
    int u, v; cin >> u >> v;
    try_merge(u, v);
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int co; cin >> co;
      pq.push({co, i, j});
    }
  }
  
  int tot = 0, cnt = 0;
  vector<pair<int, int>> ed;
  while (!pq.empty()) {
    auto [co, u, v] = pq.top(); pq.pop();
    if (u == 1 || v == 1) continue;
    if (!try_merge(u, v)) continue;
    cnt++;
    tot += co;
    ed.push_back({u, v});
  }
  
  cout << tot << ' ' << cnt << '\n';
  for (auto [u, v] : ed)
    cout << u << ' ' << v << '\n';

}
