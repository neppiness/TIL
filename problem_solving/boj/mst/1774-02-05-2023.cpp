#include <bits/stdc++.h>
using namespace std;

const int MX = 1'000;

vector<tuple<double, int, int>> e;
pair<int, int> coord[MX + 2];
int p[MX + 2];

int find(int x) {
  if(p[x] < 0) return x;
  return p[x] = find(p[x]);
}

bool try_merge(int u, int v) {
  u = find(u); v = find(v);
  if(u == v) return 0;
  if(p[u] > p[v]) swap(u, v);
  p[u] += p[v];
  p[v] = u;
  return 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(p, -1, sizeof(p));
  cout.precision(2);
  cout << fixed;

  int n, m; cin >> n >> m;
  for(int i = 1; i <= n; i++) {
    int x, y; cin >> x >> y;
    coord[i] = {x, y};
  }

  while(m--) {
    int u, v; cin >> u >> v;
    try_merge(u, v);
  }

  for(int i = 2; i <= n; i++) { 
    for(int j = 1; j < i; j++) {
      double dx = coord[i].first - coord[j].first;
      double dy = coord[i].second - coord[j].second;
      double len = hypot(dx, dy);
      e.push_back({len, i, j});
    }
  }

  sort(e.begin(), e.end());

  double ans = 0;
  int cnt = 0;
  for(auto [co, u, v] : e) {
    if(!try_merge(u, v)) continue;
    ans += co;
    cnt++;
    if(cnt == n - 1) break;
  }
  cout << ans;
}