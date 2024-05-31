#include <bits/stdc++.h>
using namespace std;

const int MOD = 1'000'000;
int dp[1'000'002];

int solve(int x) {
  int &ret = dp[x];
  if (ret != -1) return ret;

  ret = solve(x - sqrt(x));
  ret += solve(log(x));
  ret %= MOD;
  ret += solve(x * sin(x) * sin(x));
  return ret = ret % MOD;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(dp, -1, sizeof(dp));
  dp[0] = 1;
  
  int x; cin >> x;
  while (x != -1) {
    cout << solve(x) << '\n';
    cin >> x;
  }
}
