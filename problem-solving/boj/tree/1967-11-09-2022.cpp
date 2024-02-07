#include <bits/stdc++.h>
using namespace std;

const int MX = 10002;

int n, mr, mx;
bool vis[MX];
vector<pair<int, int>> adj[MX];

void solve(int cur, int sum) {
  if(sum > mx) {
    mr = cur;
    mx = sum;
  }
  vis[cur] = 1;
  for(auto [nxt, cost] : adj[cur]) {
    if(vis[nxt]) continue;
    solve(nxt, sum + cost);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  int u, v, cost;
  for(int i = 0; i < n - 1; i++) {
    cin >> u >> v >> cost;
    adj[u].push_back({v, cost});
    adj[v].push_back({u, cost});
  }

  solve(1, 0);

  fill(vis, vis + n + 1, 0);
  solve(mr, 0);

  cout << mx;
}