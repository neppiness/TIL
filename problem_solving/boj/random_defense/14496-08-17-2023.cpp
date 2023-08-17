#include <bits/stdc++.h>
using namespace std;

int st, en;
int n, m;
vector<int> adj[1002];
int dist[1002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(dist, -1, sizeof(dist));

  cin >> st >> en;
  cin >> n >> m;
  
  while (m--) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  queue<int> q;
  q.push(st);
  dist[st] = 0;
  while (!q.empty()) {
    int cur = q.front(); q.pop();
    for (int nxt : adj[cur]) {
      if (dist[nxt] != -1) continue;
      dist[nxt] = dist[cur] + 1;
      q.push(nxt);
    }
  }
  cout << dist[en];
}
