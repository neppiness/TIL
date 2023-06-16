#include <bits/stdc++.h>
using namespace std;

int n, p[3002];
tuple<int, int, int> a[3002];
set<int> pars;

int find(int x) {
  if (p[x] < 0) return x;
  return p[x] = find(p[x]);
}

void try_merge(int u, int v) {
  u = find(u); v = find(v);
  if (u == v) return;
  if (p[u] > p[v]) swap(u, v);
  p[u] += p[v];
  p[v] = u;
}

bool adj(int u, int v) {
  auto [x1, y1, r1] = a[u];
  auto [x2, y2, r2] = a[v];
  int R = (r1 + r2) * (r1 + r2);
  int ctc = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
  return ctc <= R;
}

void solve() {
  memset(p, -1, sizeof(p));
  pars.clear();

  cin >> n;

  for (int i = 0; i < n; i++) {
    int x, y, r; cin >> x >> y >> r;
    a[i] = {x, y, r};
  }

  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      if (adj(i, j)) try_merge(i, j);
  
  for (int i = 0; i < n; i++) {
    int par = find(i);
    pars.insert(par);
  }
  cout << pars.size() << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) solve();
}