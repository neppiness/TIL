#include <bits/stdc++.h>
using namespace std;

int n;
int p[100002];
int dis[100002];
vector<pair<int, int>> adj[100002]; // {dist, nxt node}

int solve() {
  return 0;
}

void find() {
  for(int i = 1; i <= n; i++) {
    for(auto cur : adj[i]) {

    }
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  fill(p, p + n + 1, -1);

  int u, v, d;
  for(int i = 0; i < n; i++) {
    cin >> u >> v;
    while(v != -1) {
      cin >> d;
      adj[u].push_back({d, v});
      cin >> v;
    }
  }
  find();
  cout << solve();
}