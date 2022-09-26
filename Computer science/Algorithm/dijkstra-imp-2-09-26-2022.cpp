#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

const int INF = 987987987;

int d[8];
bool fix[8]; // fixed nodes
vector<pair<int,int>> adj[8];
priority_queue< tuple<int, int, int>,
                vector<tuple<int, int, int>>,
                greater<tuple<int, int, int>> > pq;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  while(m--){
    int u, v, c; cin >> u >> v >> c;
    adj[u].push_back({v, c});
    adj[v].push_back({u, c});
  }
  fill(d, d + n + 1, INF);
  
  int idx; cin >> idx; // start node index
  fix[idx] = 1, d[idx] = 0;

  for(auto cur : adj[idx])
    pq.push({d[idx] + cur.Y, idx, cur.X});

  while(!pq.empty()){
    auto cur = pq.top(); pq.pop();
    int cost, u, v;
    tie(cost, u, v) = cur;
    if(fix[v]) continue;
    d[v] = cost;
    fix[v] = 1;
    idx = v;
    for(auto cur : adj[idx])
      pq.push({d[idx] + cur.Y, idx, cur.X});
  }

  for(int i = 1; i <= n; i++) cout << d[i] << ' ';
}

/*
input:
6 8
1 2 3
1 3 2
1 4 5
2 3 2
2 5 8
3 4 2
4 5 6
5 6 1
1
*/