#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

const int INF = 0x3f3f3f3f;

int n, m;
int u, v, w;
int d[1002], prv[1002];
vector<pair<int, int>> adj[1002];

priority_queue< pair<int, int>,
                vector<pair<int, int>>, 
                greater<pair<int, int>> > pq;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  fill(d, d + n + 1, INF);

  while(m--){
    cin >> u >> v >> w;
    adj[u].push_back({w, v});
    prv[v] = u;
  }
  int st, en;
  cin >> st >> en;

  d[st] = 0;
  pq.push({0, st});
  while(!pq.empty()){
    auto curr = pq.top(); pq.pop();
    u = curr.Y; w = curr.X;
    if(d[u] != w) continue;
    for(auto next : adj[u]) {
      v = next.Y;
      int dw = next.X;
      if(w + dw < d[v]) {
        d[v] = w + dw;
        pq.push({d[v], v});
        prv[v] = u;
      }
    }
  }

  int cur = en;
  stack<int> stk;
  while(1) {
    stk.push(cur);
    if(cur == st) break;
    cur = prv[cur];
  }
  cout << d[en] << '\n';
  cout << stk.size() << '\n';
  while(!stk.empty()) {
    int cur = stk.top(); stk.pop();
    cout << cur << ' ';
  }
}