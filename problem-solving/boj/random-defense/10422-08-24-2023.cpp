#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;

ll dp[5002];

ll solve(int cur) {
  if (cur % 2) return 0;
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

  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    cout << solve(n) << '\n';
  }
}
