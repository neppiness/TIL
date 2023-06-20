#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1'000'000'007;

ll dp[1'000'002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  dp[0] = 1; dp[1] = 2; dp[2] = 7;
  int n; cin >> n;
  for (int i = 3; i <= n; i++) {
    dp[i] = 3*dp[i - 1] + dp[i - 2] - dp[i - 3];
    dp[i] %= MOD;
    if (dp[i] < 0) dp[i] += MOD;
  }
  cout << dp[n];
}