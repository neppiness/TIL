#include <bits/stdc++.h>
using namespace std;

const int MX = 1000;

int n, m, k;
multiset<int> dist[MX + 2];
vector<pair<int, int>> adj[MX + 2]; // adj[cur] = {cost, nxt}

priority_queue<pair<int, int>,
    vector<pair<int, int>>,
    greater<pair<int, int>> > pq;

// nodes are 1-indexed
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> k;
  while(m--) {
    int u, v, co;
    cin >> u >> v >> co;
    adj[u].push_back({co, v});
  }

  dist[1].insert(0);
  pq.push({0, 1});
  while(!pq.empty()) {
    auto [co, cur] = pq.top(); pq.pop();
    for(auto [dco, nxt] : adj[cur]) {
      dco += co;
      int mx = *(dist[nxt].rbegin());
      if(dist[nxt].size() <= k)
    }

  }
}