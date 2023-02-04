#include <bits/stdc++.h>
using namespace std;

const int NMX = 10'000;
const int MMX = 100'000;

vector<pair<int, int>> adj[NMX + 2];
int dist[NMX + 2], ind[NMX +2];

int n, m, c;

void setup() {
  memset(dist, -1, sizeof(dist));
  memset(ind, 0, sizeof(ind));

  cin >> n >> m >> c;
  for(int i = 1; i <= n; i++)
    adj[i].clear();

  while(m--) {
    int u, v, t;
    cin >> u >> v >> t;
    adj[v].push_back({t, u});
    ind[u]++;
  }
}

void solve() {
  setup();
  vis[c] = 1;


}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) solve();
}