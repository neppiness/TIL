#include <bits/stdc++.h>
using namespace std;

const int NMX = 500'000;
const int ROOT = 1;

int depth[NMX + 2];
int p[NMX + 2];
vector<int> adj[NMX + 2];
long long cnt;

void setTree(int cur) {
  bool is_leaf = 1;
  for(int nxt : adj[cur]) {
    if(p[cur] == nxt) continue;
    is_leaf = 0;
    p[nxt] = cur;
    depth[nxt] = depth[cur] + 1;
    setTree(nxt);
  }
  if(is_leaf) cnt += depth[cur];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(p, -1, sizeof(p));

  int n; cin >> n;
  for(int i = 1; i < n; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  setTree(ROOT);

  if(cnt % 2) cout << "Yes";
  else cout << "No";
}