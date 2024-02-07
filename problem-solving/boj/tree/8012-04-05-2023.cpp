#include <bits/stdc++.h>
using namespace std;

const int LMX = 15; // 2^15 = 32,768, 해당 비트는 켜지지 않는다.
const int NMX = 30'000;
const int ROOT = 1;

int n, m, st, en, ans;
int p[NMX + 2][LMX];
int d[NMX + 2]; // depth from ROOT;
vector<int> adj[NMX + 2];

void treeSetup(int cur) {
  for(int nxt : adj[cur]) {
    if(p[cur][0] == nxt) continue;
    p[nxt][0] = cur;
    d[nxt] = d[cur] + 1;
    treeSetup(nxt);
  }
}

void stSetup() {
  for(int j = 1; j < LMX; j++) {
    for(int i = 1; i <= n; i++) {
      int cur = p[i][j - 1];
      if(cur == -1) continue;
      p[i][j] = p[cur][j - 1];
    }
  }
}

void calc() {
  int u = st, v = en;
  // u의 깊이가 v의 깊이보다 항상 크거나 같음.
  if(d[u] < d[v]) swap(u, v);
  int diff = d[u] - d[v];

  for(int i = 0; diff; i++) {
    if(diff & 1) u = p[u][i];
    diff >>= 1;
  }

  for(int lg = LMX - 1; lg >= 0; lg--) {
    if(p[u][lg] == p[v][lg]) continue;
    u = p[u][lg]; v = p[v][lg];
  }
  int w = u;
  if(u != v) w = p[u][0];

  ans += d[st] + d[en] - 2*d[w];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(p, -1, sizeof(p));

  cin >> n;
  for(int i = 1; i < n; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  treeSetup(ROOT);
  stSetup();

  cin >> m;
  st = ROOT;
  while(m--) {
    cin >> en;
    calc();
    swap(st, en);
  }
  cout << ans;
}