#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 9;

int dp[1002][1002];

int solve(int no, int tot) {
  if (tot < 0) return 0;
  int &ret = dp[no][tot];
  if (ret != -1) return ret;
  if (no == 0) return ret = (tot == 0);

  ret = 0;
  for (int i = 1; i <= 3; i++) {
    ret += solve(no - 1, tot - i);
    if (ret >= MOD) ret -= MOD;
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(dp, -1, sizeof(dp));

  int t; cin >> t;
  while (t--) {
    int n, m; cin >> n >> m;
    cout << solve(m, n) << '\n';
  }
}