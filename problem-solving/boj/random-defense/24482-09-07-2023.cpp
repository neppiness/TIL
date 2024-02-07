#include <bits/stdc++.h>
using namespace std;

set<int> edge[100'002];
int d[100'002];

void dfs(int cur) {
  for (auto it = edge[cur].rbegin(); it != edge[cur].rend(); it++) {
    if (d[*it] != -1) continue;
    d[*it] = d[cur] + 1;
    dfs(*it);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(d, -1, sizeof(d));

  int n, m, r;
  cin >> n >> m >> r;
  while (m--) {
    int u, v; cin >> u >> v;
    edge[u].insert(v);
    edge[v].insert(u);
  }

  d[r] = 0;
  dfs(r);
  for (int i = 1; i <= n; i++)
    cout << d[i] << '\n';
}
