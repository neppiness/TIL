#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// constant declaration
const int LMX = 17; // 2^17 = 131,072
const int MX = 100'000;
const int ROOT = 1;

int n, m;

// Tree info.
int p[MX + 2][LMX + 2];
ll dist[MX + 2];
int depth[MX + 2];
vector<pair<int, int>> adj[MX + 2]; // adj[cur] = {cost, nxt}

void treeSetup(int cur) {
  for(auto [cost, nxt] : adj[cur]) {
    if(p[cur][0] == nxt) continue;
    p[nxt][0] = cur;
    depth[nxt] = depth[cur] + 1;
    dist[nxt] = dist[cur] + cost; 
    treeSetup(nxt);
  }
}

int move(int cur, int diff) {
  for(int i = 0; diff; i++) {
    if(diff % 2) cur = p[cur][i];
    diff /= 2;
  }
  return cur;
}

int lca(int u, int v) {
  if(depth[u] < depth[v]) swap(u, v);
  u = move(u, depth[u] - depth[v]);

  if(u == v) return u;
  for(int i = LMX - 1; i >= 0; i--) {
    int pu = p[u][i], pv = p[v][i];
    if(pu == pv) continue;
    u = pu; v = pv;
  }
  return p[u][0];
}

int kthnode(int u, int v, int k) {
  int w = lca(u, v);
  int tot_depth = depth[u] + depth[v] - 2*depth[w];

  if(depth[u] - depth[w] < k) {
    int diff = tot_depth - k;
    v = move(v, diff);
    return v;
  } else {
    u = move(u, k);
    return u;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(p, -1, sizeof(p));

  cin >> n;
  for(int i = 1; i < n; i++) {
    int u, v, cost;
    cin >> u >> v >> cost;
    adj[u].push_back({cost, v});
    adj[v].push_back({cost, u});
  }

  treeSetup(ROOT);

  for(int j = 1; j < LMX; j++)
    for(int i = 1; i <= n; i++) {
      int cur = p[i][j - 1];
      if(cur == -1) continue;
      p[i][j] = p[cur][j - 1];
    }

  cin >> m;
  while(m--) {
    int code, u, v;
    cin >> code >> u >> v;
    if(code == 1) {
      int w = lca(u, v);
      cout << dist[u] + dist[v] - 2*dist[w]  << '\n';
    } else {
      int k; cin >> k;
      cout << kthnode(u, v, k - 1) << '\n';
    }
  }
}