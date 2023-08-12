#include <bits/stdc++.h>
using namespace std;

int n, root, dest;
int p[100'002];
queue<int> q;
vector<pair<int, int>> adj[100'002];

void treeSetup(int cur) {
  for (auto [co, nxt] : adj[cur]) {
    if (p[nxt]) continue;
    p[nxt] = cur;
    treeSetup(nxt);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> root >> dest;
  for (int i = 1; i < n; i++) {
    int u, v, co; cin >> u >> v >> co;
    adj[u].push_back({co, v});
    adj[v].push_back({co, u});
  }

  p[root] = -1;
  treeSetup(root);
  
  int tot = 0, mx = 0;
  int cur = dest;
  while (cur != root) {
    for (auto [co, nxt] : adj[cur]) {
      if (nxt != p[cur]) continue;
      tot += co; mx = max(mx, co);
      cur = nxt;
      break;
    }
  }
  cout << tot - mx;
}