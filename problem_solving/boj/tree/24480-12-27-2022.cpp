#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100'002];
int vis[100'002];
int cnt = 1;

void dfs(int cur) {
  vis[cur] = cnt++;
  for(int nxt : adj[cur])
    if(!vis[nxt]) dfs(nxt);
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

  dfs(r);

  for(int i = 1; i <= n; i++)
    cout << vis[i] << '\n';
}