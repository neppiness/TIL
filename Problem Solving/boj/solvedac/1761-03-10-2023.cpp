#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MX = 40'000;
const int LMX = 16; // 2^16 = 65,536
const int ROOT = 1;

int n, m;
int p[MX + 2][LMX + 2];
vector<pair<int, int>> adj[MX + 2];
int dth[MX + 2]; ll dist[MX + 2];

void setTree(int cur) {
  for(auto [d, nxt] : adj[cur]) {
    if(p[cur][0] == nxt) continue;
    p[nxt][0] = cur;
    dist[nxt] = dist[cur] + d;
    dth[nxt] = dth[cur] + 1;
    setTree(nxt);
  }
}

void setSt() {
  for(int j = 1; j < LMX; j++) {
    for(int i = 1; i <= n; i++) {
      int cur = p[i][j - 1];
      if(cur == -1) continue;
      p[i][j] = p[cur][j - 1];
    }
  }
}

int lca(int u, int v) {
  if(dth[u] < dth[v]) swap(u, v);

  int diff = dth[u] - dth[v];
  for(int j = 0; diff; j++) {
    if(diff % 2) u = p[u][j];
    diff /= 2;
  }

  if(u == v) return v;
  for(int j = LMX - 1; j >= 0; j--) {
    int pu = p[u][j], pv = p[v][j];
    if(pu == pv) continue;
    u = pu; v = pv;
  }
  return p[u][0];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(p, -1, sizeof(p));

  cin >> n;
  for(int i = 1; i < n; i++) {
    int u, v, d;
    cin >> u >> v >> d;
    adj[u].push_back({d, v});
    adj[v].push_back({d, u});
  }

  setTree(ROOT);
  setSt();

  cin >> m;
  while(m--) {
    int u, v; cin >> u >> v;
    int w = lca(u, v);
    cout << dist[u] + dist[v] - 2*dist[w] << '\n';
  }
}