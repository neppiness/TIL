#include <bits/stdc++.h>
using namespace std;

const int MX = 500'000;
int p[MX + 2];

int find(int cur) {
  if(p[cur] < 0) return cur;
  return p[cur] = find(p[cur]);
}

void merge(int u, int v) {
  if(p[u] > p[v]) swap(u, v);
  p[u] += p[v];
  p[v] = u;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(p, -1, sizeof(p));

  int n, m; cin >> n >> m;

  for(int i = 1; i <= m; i++) {
    int u, v; cin >> u >> v;
    u = find(u); v = find(v);
    if(u != v) {
      merge(u, v);
      continue;
    }
    cout << i;
    return 0;
  }
  cout << 0;
}