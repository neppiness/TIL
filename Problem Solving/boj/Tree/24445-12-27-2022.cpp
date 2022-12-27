#include <bits/stdc++.h>
using namespace std;

const int MX = 100'002;

vector<int> adj[MX];
queue<int> q;
int vis[MX];
int cnt = 1;

void bfs(int root) {
  vis[root] = cnt++;
  q.push(root);
  while(!q.empty()) {
    int cur = q.front(); q.pop();
    for(int nxt : adj[cur]) {
      if(vis[nxt]) continue;
      vis[nxt] = cnt++;
      q.push(nxt);
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m, r;
  cin >> n >> m >> r;
  for(int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for(int i = 1; i <= n; i++)
    sort(adj[i].rbegin(), adj[i].rend());

  bfs(r);

  for(int i = 1; i <= n; i++)
    cout << vis[i] << '\n';
}