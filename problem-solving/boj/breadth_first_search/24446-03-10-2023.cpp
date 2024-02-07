#include <bits/stdc++.h>
using namespace std;

const int MX = 100'000;

vector<int> adj[MX + 2];
queue<int> q;
int dist[MX + 2];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(dist, -1, sizeof(dist));

  int n, m, r;
  cin >> n >> m >> r;

  while(m--) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dist[r] = 0;
  q.push(r);

  while(!q.empty()) {
    int cur = q.front(); q.pop();
    for(int nxt : adj[cur]) {
      if(dist[nxt] != -1) continue;
      dist[nxt] = dist[cur] + 1;
      q.push(nxt);
    }
  }
  for(int i = 1; i <= n; i++)
    cout << dist[i] << '\n';
}