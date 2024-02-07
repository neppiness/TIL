#include <bits/stdc++.h>
using namespace std;

long long tot;
bool vis[10002];
vector<int> trnode;
vector<pair<int, int>> adj[10002]; // indexed by start node, returns end node and cost

priority_queue< tuple<int, int, int>,
                vector<tuple<int, int, int>>,
                greater<tuple<int, int, int>> > pq;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  int u, v, c;
  for(int i = 0; i < m; i++) {
    cin >> u >> v >> c;
    adj[u].push_back({v, c});
    adj[v].push_back({u, c});
  }

  int cur = 1;
  trnode.push_back(cur);
  vis[cur] = 1;
  while(trnode.size() != n) {
    for(auto x : adj[cur])
      pq.push({x.second, cur, x.first});

    while(!pq.empty()) {
      auto y = pq.top(); pq.pop();
      tie(c, u, v) = y;

      if(vis[v]) continue;
      vis[v] = 1;
      trnode.push_back(v);
      cur = v;
      tot += c;
      break;
    }
  }
  cout << tot;
}
