#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const int MX = 100'002;

int no; ll mx;

ll dist[MX];
vector<pair<int, int>> adj[MX];
vector<ll> mxLen;

int nxt, cost;
void solve(int cur) {

  for(auto a : adj[cur]) {
    tie(nxt, cost) = a;
    if(dist[nxt] != -1) continue;
    dist[nxt] = 0;
    solve(nxt);
    if(!dist[nxt]) {
      dist[nxt] = dist[cur] + cost;
    } else {
      mx = max(mx, dist[nxt] + dist[cur] + cost);
      dist[nxt] = dist[cur] + cost;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> no;

  int u, v;
  for(int i = 0; i < no; i++) {
    cin >> u >> v;
    while(v != -1) {
      cin >> cost;
      adj[u].push_back({v, cost});
      cin >> v;
    }
  }

  fill(dist, dist + MX, -1);
  solve(1);
  cout << mx;
}