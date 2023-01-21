#include <bits/stdc++.h>
using namespace std;

const int MX = 1'000'000;

int p[MX + 2];

int find(int cur) {
  if(p[cur] < 0) return cur;
  return p[cur] = find(p[cur]);
}

void merge(int u, int v) {
  u = find(u); v = find(v);
  if(u == v) return;
  if(p[u] > p[v]) swap(u, v);
  p[u] += p[v];
  p[v] = u;
}

void chk(int u, int v) {
  u = find(u); v = find(v);
  if(u == v) cout << "YES\n";
  else cout << "NO\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(p, -1, sizeof(p));

  int n, m; cin >> n >> m;
  while(m--) {
    bool op;
    int u, v;
    cin >> op >> u >> v;
    if(op == 0) merge(u, v);
    else chk(u, v);
  }
}
