#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 0x3f3f3f3f3f3f3f;

ll c, d[100002];
int n, m, st, en;

vector<pair<ll, int>> adj[100002];
priority_queue< tuple<ll, ll, int>, 
                vector<tuple<ll, ll, int>>,
                greater<tuple<ll, ll, int>> > pq;

ll solve(){
  fill(d, d + n + 1, INF);
  d[st] = 0;
  pq.push({d[st], 0, st});
  while(!pq.empty()){
    int u, v;
    ll w, dw, tc;
    tie(w, tc, u) = pq.top(); pq.pop();
    if(d[u] != w) continue;
    for(auto nxt : adj[u]){
      tie(dw, v) = nxt;
      if(tc + dw > c) continue;
      dw = max(dw, w);
      if(dw >= d[v]) continue;
      d[v] = dw;
      pq.push({dw, tc + dw, v});
    }
  }
  if(d[en] == INF) d[en] = -1;
  return d[en];
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> st >> en >> c;

  int u, v; ll w;
  while(m--){
    cin >> u >> v >> w;
    adj[u].push_back({w, v});
    adj[v].push_back({w, u});
  }
  cout << solve();
}