#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[120];

ll solve(int x) {
  ll &ret = dp[x];
  if (ret != -1) return ret;
  return ret = solve(x - 1) + solve(x - 3);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(dp, -1, sizeof(dp));
  dp[1] = 1;
  dp[2] = 1;
  dp[3] = 1;

  int n; cin >> n;
  cout << solve(n);
}
