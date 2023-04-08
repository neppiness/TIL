#include <bits/stdc++.h>
using namespace std;

const int MX = 10'000;

vector<pair<int, int>> adj[MX + 2];
vector<pair<int, int>> inv_adj[MX + 2];
int n, m, ans, st, en;
int dist[MX + 2], d_chk[MX + 2];
bool vis[MX + 2];

priority_queue<pair<int, int>> pq;
queue<int> q;

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  while(m--) {
    int u, v, co;
    cin >> u >> v >> co;
    adj[u].push_back({co, v});
    inv_adj[v].push_back({co, u});
  }
  cin >> st >> en;

  pq.push({0, st});
  while(!pq.empty()) {
    auto [co, cur] = pq.top(); pq.pop();
    if(dist[cur] != co) continue;
    for(auto [dco, nxt] : adj[cur]) {
      dco += co;
      if(dist[nxt] > dco) continue;
      dist[nxt] = dco;
      pq.push({dco, nxt});
    }
  }

  vis[en] = 1; q.push(en);
  d_chk[en] = dist[en];
  while(!q.empty()) {
    int cur = q.front(); q.pop();
    for(auto [d, nxt] : inv_adj[cur]) {
      d_chk[nxt] = d_chk[cur] - d;
      if(d_chk[nxt] == dist[nxt]) ans++;
      if(vis[nxt]) continue;
      vis[nxt] = 1; q.push(nxt);
    }
  }
  cout << dist[en] << '\n' << ans;
}