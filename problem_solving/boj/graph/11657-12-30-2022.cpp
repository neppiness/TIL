#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 0x7f7f7f7f7f7f7f;
const ll LM = 0x3f3f3f3f3f3f3f;
const int NMX = 502;

vector<pair<int, int>> adj[NMX]; // adj[cur] = {cost, nxt};
ll dist[NMX];

int main() {
  fill(dist, dist + NMX, INF);
  dist[1] = 0;

  int n, m; cin >> n >> m;
  while(m--) {
    int u, v, cost;
    cin >> u >> v >> cost;
    adj[u].push_back({cost, v});
  }

  bool isvalidupdate;
  for(int i = 0; i < n; i++) { // loop for n-time
    isvalidupdate = 0;
    for(int cur = 1; cur <= n; cur++) {
      for(auto [cost, nxt] : adj[cur]) {
        if(dist[nxt] <= cost + dist[cur]) continue;
        dist[nxt] = cost + dist[cur];
        if(dist[nxt] >= LM) continue;
        isvalidupdate = 1;
      }
    }
    if(!isvalidupdate) break;
  }
  if(isvalidupdate) {
    cout << -1;
    return 0;
  }

  // print ans
  for(int i = 2; i <= n; i++) {
    if(dist[i] >= LM) cout << -1 << '\n';
    else cout << dist[i] << '\n';
  }
}