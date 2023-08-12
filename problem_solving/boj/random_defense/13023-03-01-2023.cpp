#include <bits/stdc++.h>
using namespace std;

const int MX = 2'000;

int n, m;
int dist[MX + 2];
vector<int> adj[MX + 2];

bool solve() {
  for(int i = 0; i < n; i++) {
    memset(dist, -1, sizeof(dist));
    if(bfs() >= 
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

  cout << solve();
}