#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int dp[5002][2];

int solve(int x, int is_unit) {
  int &ret = dp[x][is_unit];
  if (ret != -1) return ret;

  ret = 0;
  if (is_unit) {
    ret += solve(x - 2, 0) + solve(x - 2, 1);
    if (ret >= MOD) ret -= MOD;
  } else {
    for (int i = 2; i <= x - 2; i += 2) {
      ret += solve(i, 1) + solve(x - i, 1);
      if (ret >= MOD) ret -= MOD;
    }
  }

}

int solve(int x) {
  if (x % 2) return 0;
  int ans = solve(x, 0) + solve(x, 1);
  if (ans >= MOD) ans -= MOD;
  return ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(dp, -1, sizeof(dp));

  int t; cin >> t;
  while (t--) {
    int x; cin >> x;
    cout << solve(x) << '\n';
  }
}