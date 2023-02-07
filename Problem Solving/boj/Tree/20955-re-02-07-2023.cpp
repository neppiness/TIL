#include <bits/stdc++.h>
using namespace std;

const int MX = 100'000;

int n, m;
int cnt, p[MX + 2];

int find(int x) {
  if(p[x] < 0) return x;
  return p[x] = find(p[x]);
}

void try_merge(int u, int v) {
  u = find(u); v = find(v);
  if(u == v) { cnt++; return; }
  if(p[u] > p[v]) swap(u, v);
  p[u] += p[v];
  p[v] = u;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(p, -1, sizeof(p));

  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    try_merge(u, v);
  }
  cout << n - m - 1 + 2*cnt;
}