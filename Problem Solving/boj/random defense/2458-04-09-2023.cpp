#include <bits/stdc++.h>
using namespace std;

const int MX = 502;

vector<int> adj[MX], inv_adj[MX];
int n, m, cnt, ans;
bool vis[MX];

void dfs(int cur) {
  for(int nxt : adj[cur]) {
    if(vis[nxt]) continue;
    cnt++;
    vis[nxt] = 1;
    dfs(nxt);
  }
}

void inv_dfs(int cur) {
  for(int nxt : inv_adj[cur]) {
    if(vis[nxt]) continue;
    cnt++;
    vis[nxt] = 1;
    inv_dfs(nxt);
  }
}

void solve(int cur) {
  cnt = 0;
  memset(vis, 0, sizeof(vis));
  vis[cur] = 1;
  dfs(cur); inv_dfs(cur);
  if(cnt == n - 1) ans++;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  while(m--) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    inv_adj[v].push_back(u);
  }

  for(int i = 1; i <= n; i++)
    solve(i);
  cout << ans;
}