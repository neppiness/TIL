#include <bits/stdc++.h>
using namespace std;

const int MX = 20'000;

vector<int> adj[MX + 2];
int dist[MX + 2], mx;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(dist, -1, sizeof(dist));

  int n, m; cin >> n >> m;

  while(m--) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  queue<int> q;
  q.push(1);
  dist[1] = 0;

  // bfs
  while(!q.empty()) {
    int cur = q.front(); q.pop();
    for(int nxt : adj[cur]) {
      if(dist[nxt] != -1) continue;
      dist[nxt] = dist[cur] + 1;
      mx = max(dist[nxt], mx);
      q.push(nxt);
    }
  }
  int cnt = 0;
  for(int i = 1; i <= n; i++) {
    if(dist[i] == mx) {
      if(!cnt) cout << i << ' ';
      cnt++;
    }
  }
  cout << mx << ' ' << cnt;
}