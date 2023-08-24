#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 987654321;

ll dp[10'002];

ll solve(int cur) {
  if (cur == 0 || cur == 2) return 1;

  ll &ret = dp[cur];
  if (ret != -1) return ret;

  ret = 0;
  for (int i = 0; i <= cur - 2; i += 2) {
    ret += solve(i) * solve(cur - 2 - i);
    if (ret >= MOD) ret %= MOD;
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(dp, -1, sizeof(dp));

  int n; cin >> n;
  cout << solve(n);
}
