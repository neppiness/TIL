#include <bits/stdc++.h>
using namespace std;

const int NMX = 10'000;
const int MMX = 100'000;
const int INF = 0x7f7f7f7f;

vector<pair<int, int>> adj[NMX + 2];
int dist[NMX + 2];

int n, m, st;

void setup() {
  memset(dist, 0x7f, sizeof(dist));

  cin >> n >> m >> st;
  for(int i = 1; i <= n; i++)
    adj[i].clear();

  while(m--) {
    int u, v, cost;
    cin >> u >> v >> cost;
    adj[v].push_back({cost, u});
  }
}

void solve() {
  setup();
  priority_queue< pair<int, int>, 
      vector<pair<int, int>>,
      greater<pair<int, int>> > pq;
  pq.push({0, st});
  dist[st] = 0;

  while(!pq.empty()) {
    auto [co, u] = pq.top(); pq.pop();
    if(dist[u] != co) continue;
    for(auto [dco, v] : adj[u]) {
      dco += co;
      if(dist[v] <= dco) continue;
      dist[v] = dco;
      pq.push({dco, v});
    }
  }
  int cnt = 0, ans = 0;
  for(int i = 1; i <= n; i++) {
    if(dist[i] == INF) continue;
    cnt++;
    ans = max(ans, dist[i]);
  }
  cout << cnt << ' ' << ans << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) solve();
}