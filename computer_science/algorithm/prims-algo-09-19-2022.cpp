#include <bits/stdc++.h>
using namespace std;

long long tot;
bool vis[10002];
vector<int> trnode;
vector<pair<int, int>> edges;
vector<pair<int, int>> adj[10002]; // indexed by start node, returns end node and cost

class cmp {
  public:
  bool operator() (tuple<int, int, int> a, tuple<int, int, int> b) {
    return a > b;
  }
};

priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, cmp> pq;

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

      if(vis[u] && vis[v]) continue;
      if(!vis[u]) {
        vis[u] = 1;
        trnode.push_back(u);
        cur = u;
        edges.push_back({u, v});
        break;
      }
      if(!vis[v]) {
        vis[v] = 1;
        trnode.push_back(v);
        cur = v;
      }
      tot += c;
      edges.push_back({u, v});
      break;
    }
  }
  cout << tot;
}

/*
Test case:
5 7
1 2 4
1 4 3
1 3 3
3 5 5
3 4 3
4 5 6
2 5 8
*/