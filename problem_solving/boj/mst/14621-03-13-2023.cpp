#include <bits/stdc++.h>
using namespace std;

const int MX = 1'000;

int n, m; 
int p[MX + 2];
bool is_w[MX + 2];
vector<tuple<int, int, int>> e; // e = {cost, u, v}

int find(int u) {
  if(p[u] < 0) return u;
  return p[u] = find(p[u]);
}

void merge(int u, int v) {
  if(u == v) return;
  if(p[u] > p[v]) swap(u, v);
  p[u] += p[v];
  p[v] = u;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(p, -1, sizeof(p));

  cin >> n >> m;
  for(int i = 1; i <= n; i++) {
    char c; cin >> c;
    if(c == 'W') is_w[i] = 1;
  }

  for(int i = 0; i < m;i ++) {
    int u, v, cost;
    cin >> u >> v >> cost;
    if(is_w[u] == is_w[v]) continue;
    e.push_back({cost, u, v});
  }
  sort(e.begin(), e.end());

  int ans = 0;
  for(auto [co, u, v] : e) {
    int pu = find(u), pv = find(v);
    if(pu == pv) continue;
    merge(pu, pv);
    ans += co;
  }
  if(p[find(1)] != -n) ans = -1;
  cout << ans;
}