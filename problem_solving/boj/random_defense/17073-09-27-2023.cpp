#include <bits/stdc++.h>
using namespace std;

int leaf_cnt;
vector<int> adj[500'002];
int p[500'002];

void treeSetup(int cur) {
  bool is_leaf = 1;
  for (int nxt : adj[cur]) {
    if (p[nxt]) continue;
    p[nxt] = cur;
    treeSetup(nxt);
    is_leaf = 0;
  }
  if (!is_leaf) leaf_cnt--;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cout.precision(9);
  cout << fixed;

  int n, w; cin >> n >> w;
  leaf_cnt = n;
  while (--n) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  p[1] = -1;
  treeSetup(1);
  cout << (double) w / leaf_cnt << '\n';
}
