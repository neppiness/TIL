#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int p[1002];
set<tuple<int, int, int>> edge;
tuple<int, int, int> temp;

int find(int cur) {
  if (p[cur] < 0) return cur;
  return p[cur] = find(p[cur]);
}

bool try_merge(int u, int v) {
  u = find(u); v = find(v);
  if (u == v) return 0;
  if (p[u] > p[v]) swap(u, v);
  p[u] += p[v];
  p[v] = u;
  return 1;
}

bool is_solved() {
  for (int u = 1; u <= n; u++)
    for (int v = u + 1; v <= n; v++) {
      int pu = find(u);
      int pv = find(v);
      if (pu != pv) return 0;
    }
  edge.erase(temp);
  return 1;
}

int calc() {
  memset(p, -1, sizeof(p));
  int ret = 0;
  temp = {10'001, 0, 0};

  for (auto [co, u, v] : edge) {
    if (!try_merge(u, v)) continue;
    temp = min(temp, {co, u, v});
    ret += co;
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> k;
  for (int i = 1; i <= m; i++) {
    int u, v; cin >> u >> v;
    edge.insert({i, u, v});
  }

  while (k--) {
    int ans = calc();
    if (is_solved()) cout << ans << ' ';
    else cout << 0 << ' ';
  } 
}
