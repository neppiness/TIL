#include <bits/stdc++.h>
using namespace std;

int n;
int p[300'002];

int find(int x) {
  if (p[x] < 0) return x;
  return p[x] = find(p[x]);
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

  cin >> n;
  for (int i = 0; i < n - 2; i++) {
    int u, v; cin >> u >> v;
    try_merge(u, v);
  }

  int u = 1;
  for (int v = 2; v <= n; v++) {
    if (!try_merge(u, v)) continue;
    cout << u << ' ' << v;
    return 0;
  }
}