#include <bits/stdc++.h>
using namespace std;

const int MX = 300'000;

int dist[MX + 2];
vector<int> adj[MX + 2], ans;

int n, m, k, x;

void solve() {
  queue<int> q;
  dist[x] = 0;
  q.push(x);

  while(!q.empty()) {
    int cur = q.front(); q.pop();
    for(int nxt : adj[cur]) {
      if(dist[nxt] != -1) continue;
      dist[nxt] = dist[cur] + 1;
      q.push(nxt);
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(dist, -1, sizeof(dist));
  cin >> n >> m >> k >> x;
  while(m--) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
  }
  solve();

  for(int i = 1; i <= n; i++)
    if(dist[i] == k) ans.push_back(i);
  
  if(ans.size() == 0) cout << -1;
  else for(int a : ans) cout << a << '\n';
}