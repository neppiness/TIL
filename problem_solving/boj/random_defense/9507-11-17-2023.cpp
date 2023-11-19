#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[70];

ll solve(int n) {
  ll &ret = dp[n];
  if (ret != -1) return ret;
  return ret = solve(n - 1) + solve(n - 2) + solve(n - 3) + solve(n - 4);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(dp, -1, sizeof(dp));
  dp[0] = dp[1] = 1;
  dp[2] = 2;
  dp[3] = 4;

  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    cout << solve(n) << '\n';
  }
}
