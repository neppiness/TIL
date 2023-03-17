#include <bits/stdc++.h>
using namespace std;

const int MX = 1000;
const int ST = 1;

int n, m;
int d[MX + 2], prv[MX + 2];
vector<pair<int, int>> adj[MX + 2], ans;

priority_queue< pair<int ,int>, 
    vector<pair<int ,int>>,
    greater<pair<int ,int>> > pq; // pq: {cost, nxt}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(d, 0x7f, sizeof(d));
  memset(prv, -1, sizeof(prv));

  cin >> n >> m;
  while(m--) {
    int u, v, co;
    cin >> u >> v >> co;
    adj[u].push_back({co, v});
    adj[v].push_back({co, u});
  }

  d[ST] = 0;
  pq.push({0, 1});
  while(!pq.empty()) {
    auto [co, cur] = pq.top(); pq.pop();
    if(d[cur] != co) continue;
    for(auto [dco, nxt] : adj[cur]) {
      dco += co;
      if(d[nxt] <= dco) continue;
      d[nxt] = dco;
      prv[nxt] = cur;
      pq.push({dco, nxt});
    }
  }

  int cur = n;
  while(cur != ST) {
    ans.push_back({prv[cur], cur});
    cur--;
  }
  cout << ans.size() << '\n';
  for(auto [u, v] : ans)
    cout << u << ' ' << v << '\n';
}