#include <bits/stdc++.h>
using namespace std;

const int MX = 100'000 + 2;

long long ans;
int n, m, r, seq;

vector<int> adj[MX];
bool vis[MX];

void dfs(int cur, int d) {
  vis[cur] = 1;
  seq++;
  ans += (long long)seq * (long long)d;
  for(int nxt : adj[cur]) {
    if(vis[nxt]) continue;
    dfs(nxt, d + 1);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> r;
  while(m--) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for(int i = 1; i <= n; i++)
    if(adj[i].size()) sort(adj[i].begin(), adj[i].end());
  
  dfs(r, 0);
  cout << ans;
}