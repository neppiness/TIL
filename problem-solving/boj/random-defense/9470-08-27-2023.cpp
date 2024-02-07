#include <bits/stdc++.h>
using namespace std;

int dp[1002];
int n, m, k;
vector<int> adj[1002];

int solve(int cur) {
  int &ret = dp[cur];
  if (ret != -1) return ret;
  
  ret = 1;
  int mx = 1, cnt = 0;
  for (int nxt : adj[cur]) {
    int x = solve(nxt);
    if (x < mx) continue;
    if (x == mx) cnt++;
    if (x > mx) {
      mx = x;
      cnt = 1;
    }
  }
  if (cnt >= 2) return ret = mx + 1;
  return ret = mx;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  for (int i = 1; i <= t; i++) {
    memset(dp, -1, sizeof(dp));

    cin >> k >> n >> m;
    for (int i = 1; i <= n; i++)
      adj[i] = vector<int>();

    while (m--) {
      int u, v; cin >> u >> v;
      adj[v].push_back(u);
    }
    cout << k << ' ' << solve(n) << '\n';
  }
}
