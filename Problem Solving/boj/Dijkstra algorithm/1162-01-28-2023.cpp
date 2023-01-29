#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int KMX = 20;
const int NMX = 10'000;

int n, m, k;
ll dist[KMX + 2][NMX + 2];
vector<tuple<ll, int, int>> adj[NMX + 2]; // adj[u] = {cost, dk, v}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(dist, 0x3f, sizeof(dist));

  cin >> n >> m >> k;
  while(m--) {
    int u, v; ll cost;
    cin >> u >> v >> cost;
    adj[u].push_back({cost, 0, v});
    adj[v].push_back({cost, 0, u});
    adj[u].push_back({0, 1, v});
    adj[v].push_back({0, 1, u});
  }

  priority_queue< tuple<ll, int, int>,
      vector<tuple<ll, int, int>>, 
      greater<tuple<ll, int, int>> > pq; // {cost, ck, v}

  for(int i = 0; i <= k; i++)
    dist[i][1] = 0;
  pq.push({0, 0, 1});

  while(!pq.empty()) {
    auto [cc, ck, cur] = pq.top(); pq.pop();
    if(dist[ck][cur] != cc) continue;
    for(auto [dc, dk, nxt] : adj[cur]) {
      dc += cc;
      dk += ck;
      if(dc >= dist[dk][nxt]) continue;
      if(dk > k) continue;
      dist[dk][nxt] = dc;
      pq.push({dc, dk, nxt});
    }
  }

  ll ans = 0x3f3f3f3f3f3f3f;
  for(int i = 0; i <= k; i++)
    ans = min(ans, dist[i][n]);
  cout << ans;
}