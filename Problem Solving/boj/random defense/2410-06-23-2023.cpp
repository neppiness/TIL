#include <bits/stdc++.h>
using namespace std;

const int kMod = 1e9;

int dp[22][1'000'002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  dp[0][0] = 1;

  for (int i = 1; i <= n; i++) {
    for (int e = 0; e < 20; e++) {
      int ex = (1 << e);
      if (i - ex < 0) continue;
      for (int ee = 0; ee <= e; ee++) {
        dp[e][i] += dp[ee][i - ex];
        if (dp[e][i] >= kMod) dp[e][i] -= kMod;
      }
    }
  }

  int ans = 0;
  for (int e = 0; e < 20; e++) {
    ans += dp[e][n];
    if (ans >= kMod) ans -= kMod;
  }
  cout << ans;
}