#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[1002][1002]; // dp[from][to];
ll lv[1002], sum[1002];

ll solve(int from, int to) {
  if (from == to) return 0;

  ll &ret = dp[from][to];
  if (ret != -1) return ret;
  if (to - from == 1) return ret = lv[from] + lv[to];

  for (int i = to; i <= from; i++)
    ret = max(ret, sum[i] - sum[to - 1] + sum[);
  return ret;
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(dp, -1, sizeof(dp));

  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> lv[i];
    sum[i] = sum[i - 1] + lv[i];
  }
  
  cout << solve(1, n);
}
