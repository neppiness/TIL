#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[82];

ll ps(int x) {
  ll &ret = dp[x];
  if (ret != -1) return ret;
  return ret = ps(x - 1) + ps(x - 2);
}

ll solve(int n) {
  if (n == 1) {
    return 4;
  }
  ll h = ps(n - 2) + ps(n - 1);
  ll w = ps(n - 1) + ps(n);
  return h * 2 + w * 2;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(dp, -1, sizeof(dp));
  dp[0] = 0;
  dp[1] = 1;
  dp[2] = 1;

  int n; cin >> n;
  cout << solve(n);
}
