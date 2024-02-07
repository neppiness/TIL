#include <bits/stdc++.h>
using namespace std;

const int NMX = 1'000;

set<int> dist[NMX + 2];
vector<pair<int, int>> adj[NMX + 2];

priority_queue< pair<int, int>,
    vector<pair<int, int>>,
    greater<pair<int, int>> > pq;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m, k;
  cin >> n >> m >> k;
  while(m--) {
    int u, v, cost;
    cin >> u >> v >> cost;
    adj[u].push_back({cost, v});
  }

  
}