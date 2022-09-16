#include <bits/stdc++.h>
using namespace std;

int n, m;
int dist[1002][1002];
bool vis[1002];
vector<int> adj[1002];
vector<int> checked;

void solve(int cur){
  vis[cur] = 1;
  for(int nxt : adj[cur]) {
    if(vis[nxt]) continue;
    for(int prv : checked) {
      if(prv == cur) continue;
      dist[prv][nxt] = dist[cur][nxt] + dist[cur][prv];
      dist[nxt][prv] = dist[prv][nxt];
    }
    checked.push_back(nxt);
    solve(nxt);
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for(int i = 1; i <= n; i++)
    fill(dist[i] + 1, dist[i] + n + 1, 0);

  for(int i = 1; i < n; i++) {
    int u, v, d;
    cin >> u >> v >> d;
    adj[u].push_back(v);
    adj[v].push_back(u);
    dist[u][v] = d;
    dist[v][u] = d;
  }
  
  checked.push_back(1);
  solve(1);

  while(m--) {
    int i, j;
    cin >> i >> j;
    cout << dist[i][j] << '\n';
  }
}