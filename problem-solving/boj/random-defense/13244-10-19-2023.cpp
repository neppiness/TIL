#include <bits/stdc++.h>
using namespace std;

const string ANSWERS[] = {"graph", "tree"};

bool solve() {
  int n, m; cin >> n >> m;

  vector<int> adj[1'002];
  bool vis[1'002] = {};
  for (int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  queue<int> q; q.push(1);
  vis[1] = 1;
  while (!q.empty()) {
    int cur = q.front(); q.pop();
    for (int nxt : adj[cur]) {
      if (vis[nxt]) continue;
      vis[nxt] = 1;
      q.push(nxt);
    }
  }
  if (n - m != 1) return 0;
  for (int i = 1; i <= n; i++)
    if (!vis[i]) return 0;
  return 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--)
    cout << ANSWERS[solve()] << '\n';
}
