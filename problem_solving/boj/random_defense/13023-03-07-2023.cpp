#include <bits/stdc++.h>
using namespace std;

const int MX = 2000;

int n, m;
vector<int> adj[MX + 2];
int dist[MX + 2];
bool is_found = 0;

void dfs(int cur) {
  if(dist[cur] == 5) is_found = 1;
  for(int nxt : adj[cur]) {
    if(dist[nxt] != -1) continue;
    dist[nxt] = dist[cur] + 1;
    dfs(nxt);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  while(m--) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for(int st = 0; st < n; st++) {
    memset(dist, -1, sizeof(dist));
    dist[st] = 1;
    dfs(st);
  }
  cout << is_found;
}