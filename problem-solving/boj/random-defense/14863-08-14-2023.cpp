#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int n, k;
int dp[102][100'002];
vector<pair<int, int>> adj[102]; // adj[cur] = {time, cost};

int solve(int no, int t) {
  if (no == 0) return 0;

  int &ret = dp[no][t];
  if (ret != -1) return ret;
  
  ret = -INF;
  for (auto [dt, dc] : adj[no]) {
    if (t - dt < 0) continue;
    ret = max(ret, solve(no - 1, t - dt) + dc);
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(dp, -1, sizeof(dp));

  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 2; j++) {
      int dt, dc; cin >> dt >> dc;
      adj[i].push_back({dt, dc});
    }
  }
  cout << solve(n, k);
}
// solved at 2nd try. memory: 41868 kB, time: 96ms, length: 700B
