#include <bits/stdc++.h>
using namespace std;

const int NMX = 10'000;

int n, e;
vector<int> adj[NMX + 2];

int chad[NMX + 2], d[MX + 2], p[MX + 2];

int treeSetup(int cur) {
  for(int nxt : adj[cur]) {
    if(p[cur] == nxt) continue;
    if(d[nxt] < d[cur]) {
      chad[cur] = min(d[nxt], chad[cur]);
      continue;
    }
    p[nxt] = cur;
    d[nxt] = d[cur] + 1;
    treeSetup(nxt);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(chad, 0x7f, sizeof(chad));
  memset(d, 0x7f, sizeof(d));
  memset(p, -1, sizeof(p));

  cin >> n >> e;
  while(e--) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for(int cur = 1; cur <= n; cur++) {
    if(d[cur] != -1) continue;
    d[cur] = 0;
    treeSetup(cur);
  }
}