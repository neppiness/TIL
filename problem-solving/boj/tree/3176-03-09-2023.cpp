#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int NMX = 100'000;
const int LMX = 17; // 2^17 = 131,072
const int ROOT = 1;

int n, m;

ll dist[NMX + 2]; // distance from cur_node to root
int depth[NMX + 2];
int p[NMX + 2][LMX];
vector<pair<int, int>> adj[NMX + 2]; // adj[cur] = {cost, nxt}

void treeDFSetup(int cur) {
  for(auto [cost, nxt] : adj[cur]) {
    if(p[nxt][0] != -1) continue;
    p[nxt][0] = cur;
    depth[nxt] = depth[cur] + 1;
    dist[nxt] = dist[cur] + cost;
    treeDFSetup(nxt);
  } 
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(p, -1, sizeof(p));
  memset(dist, -1, sizeof(dist));
  memset(depth, -1, sizeof(depth));
  dist[ROOT] = 0; depth[ROOT] = 0;
  
  cin >> n;
  for(int i = 1; i < n; i++) {
    int u, v, cost;
    cin >> u >> v >> cost;
    adj[u].push_back({cost, v});
    adj[v].push_back({cost, u});
  }
  treeDFSetup(ROOT);

  for(int j = 1; j < LMX; j++) {
    for(int i = 1; i <= n; i++) {
      int cur = p[i][j - 1];
      if(cur == -1) continue;
      p[i][j] = p[cur][j - 1];
    }
  }

  cin >> m;
  while(m--) {
    int u, v; cin >> u >> v;
    cout 
  }

}