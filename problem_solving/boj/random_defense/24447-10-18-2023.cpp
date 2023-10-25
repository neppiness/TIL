#include <bits/stdc++.h>
using namespace std;

int seq = 1;
int d[100'002];
int vis[100'002];
set<int> adj[100'002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m, r;
  cin >> n >> m >> r;

  while (m--) {
    int u, v; cin >> u >> v;
    adj[u].insert(v);
    adj[v].insert(u);
  }

  memset(vis, -1, sizeof(vis));
  memset(d, -1, sizeof(d));


  long long ans = 0;
  queue<int> q;
  q.push(r);
  d[r] = 0;
  vis[r] = seq++;
  while (!q.empty()) {
    int cur = q.front(); q.pop();
    for (int nxt : adj[cur]) {
      if (d[nxt] != -1) continue;
      d[nxt] = d[cur] + 1;
      vis[nxt] = seq++;
      q.push(nxt);
      ans += (long long)d[nxt] * vis[nxt];
    }
  }
  cout << ans;
}
