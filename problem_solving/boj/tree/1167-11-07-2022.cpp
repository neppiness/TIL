#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const int MX = 100'002;

int no; ll mx;

ll dist[MX];

int p[MX];
vector<pair<int, int>> adj[MX];

void par(int cur) {
  int nxt, cost;
  for(auto a : adj[cur]) {
    tie(nxt, cost) = a;
    if(p[nxt]) continue;
    p[nxt] = cur;
    par(nxt);
  }
}

void solve(int cur) {
  vector<ll> d;
  int nxt, cost;
  for(auto a : adj[cur]) {
    tie(nxt, cost) = a;
    if(p[cur] == nxt) continue;
    solve(nxt);
    d.push_back(dist[nxt] + cost);
  }

  if(d.size() == 0) {
    dist[cur] = 0;
    return;
  }

  sort(d.rbegin(), d.rend());
  dist[cur] = d[0];
  if(d.size() >= 2) mx = max(mx, d[0] + d[1]);
  else mx = max(mx, d[0]);
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> no;

  int u, v;
  int nxt, cost;
  for(int i = 0; i < no; i++) {
    cin >> u >> v;
    while(v != -1) {
      cin >> cost;
      adj[u].push_back({v, cost});
      cin >> v;
    }
  }

  p[1] = -1; par(1);
  solve(1);

  int midx = max_element(dist + 1, dist + no + 1) - dist;
  mx = max(dist[midx], mx);
  cout << mx;
}