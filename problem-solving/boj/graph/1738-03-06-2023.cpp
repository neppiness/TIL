#include <bits/stdc++.h>
using namespace std;

const int MX = 100 + 2;
const int MINF = -0x3f3f3f3f;

int n, m;
int prv[MX], val[MX];
bool con[MX][MX]; // con[u][v]: connectivity of the path from node u to node v
vector<pair<int, int>> adj[MX]; // adj[cur] = {cost, nxt}

void con_chk(int st) {
  bool vis[MX] = {};
  queue<int> q;
  vis[st] = 1;
  q.push(st);
  
  while(!q.empty()) {
    int cur = q.front(); q.pop();
    for(auto [co, nxt] : adj[cur]) {
      if(vis[nxt]) continue;
      vis[nxt] = 1;
      con[cur][nxt] = 1;
      q.push(nxt);
    }
  }
}

void tr(int cur) {
  if(prv[cur] != -1) tr(prv[cur]);
  cout << cur << ' ';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  fill(val + 2, val + MX, MINF);
  fill(prv, prv + MX, -1);

  cin >> n >> m;
  while(m--) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({w, v});
  }

  for(int cur = 1; cur <= n; cur++)
    con_chk(cur);

  bool is_updated;
  for(int it = 0; it < n - 1; it++) {
    is_updated = 0;
    for(int cur = 1; cur <= n; cur++) {
      if(val[cur] == MINF) continue;
      for(auto [co, nxt] : adj[cur]) {
        int dco = co + val[cur];
        if(val[nxt] >= dco) continue;
        val[nxt] = dco;
        is_updated = 1;
        prv[nxt] = cur;
      }
    }
    if(!is_updated) break;
  }
  
  is_updated = 0;
  for(int cur = 1; cur <= n; cur++) {
    if(val[cur] == MINF) continue;
    for(auto [co, nxt] : adj[cur]) {
      int dco = co + val[cur];
      if(val[nxt] >= dco) continue;
      val[nxt] = dco;
      if(con[nxt][n]) is_updated = 1;
    }
  }
  if(is_updated || val[n] == MINF) { cout << -1; return 0; }
  tr(n);
}