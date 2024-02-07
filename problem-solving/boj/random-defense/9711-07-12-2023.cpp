#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int cnt = 1, p, q;
ll dp[10'002];

ll solve(int cur) {
  ll &ret = dp[cur];
  if (ret != -1) return ret;
  ret = solve(cur - 1) + solve(cur - 2);
  return ret %= q;
}

void solve() {
  memset(dp, -1, sizeof(dp));
  cin >> p >> q;
  dp[1] = 1 % q; dp[2] = 1 % q;
  cout << "Case #" << cnt++ << ": " << solve(p) << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) solve();
}