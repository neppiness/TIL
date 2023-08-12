#include <bits/stdc++.h>
using namespace std;

const int MX = 10000;
const int JS = 0;

vector<pair<int, int>> adj;
int n, m, k;
int p[MX + 2];

int find(int u) {
  if(p[u] < 0) return u;
  return p[u] = find(p[u]);
}

bool try_merge(int u, int v) {
  u = find(u), v = find(v);
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

  cin >> n >> m >> k;
  for(int i = 1; i <= n; i++) {
    int co; cin >> co;
    adj.push_back({co, i});
  }
  sort(adj.begin(), adj.end());

  while(m--) {
    int u, v; cin >> u >> v;
    try_merge(u, v);
  }

  int sum = 0;
  for(auto [co, v] : adj)
    if(try_merge(JS, v)) sum += co;
    
  if(sum > k) cout << "Oh no\n";
  else cout << sum;
}