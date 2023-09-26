#include <bits/stdc++.h>
using namespace std;

int n, m, r;
vector<int> adj[100'002];
int d[100'002];

void setup() {
  memset(d, -1, sizeof(d));

  cin >> n >> m >> r;
  d[r] = 0;
  while (m--) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i = 1; i <= n; i++)
    sort(adj[i].begin(), adj[i].end());
}

void dfs(int cur) {
  for (int nxt : adj[cur]) {
    if (d[nxt] != -1) continue;
    d[nxt] = d[cur] + 1;
    dfs(nxt);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  setup();
  dfs(r);
  for (int i = 1; i <= n; i++)
    cout << d[i] << '\n';
}
