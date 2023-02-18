#include <bits/stdc++.h>
using namespace std;

const int MX = 1'000 + 2;

int n, p[MX];
bool is_a[MX];

int find(int x) {
  if(p[x] < 0) return x;
  return p[x] = find(p[x]);
}

void merge(int u, int v) {
  u = find(u); v = find(v);
  if(u == v) return;
  if(p[u] > p[v]) swap(u, v);
  p[u] += p[v];
  p[v] = u;
}

void solve() {
  memset(is_a, 0, sizeof(is_a));
  memset(p, -1, sizeof(p));
  cin >> n;

  for(int i = 1; i <= n; i++) {
    int x; cin >> x;
    merge(x, i);
  }

  int ans = 0;
  for(int i = 1; i <= n; i++) {
    int pi = find(i);
    if(is_a[pi]) continue;
    is_a[pi] = 1;
    ans++;
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while(t--) solve();
}