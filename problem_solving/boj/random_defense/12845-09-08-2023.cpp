#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
ll lv[1002];
ll dp[1002][1002];
ll mx[1002][1002];

ll solve(int a, int b) {
  if (a == b) return 0;
  ll &ret = dp[a][b];
  if (ret != -1) return ret;

  for (int i = a; i < b; i++) {
    ll d = mx[a][i] + mx[i + 1][b];
    ret = max(ret, solve(a, i) + solve(i + 1, b) + d);
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(dp, -1, sizeof(dp));

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> lv[i];
    mx[i][i] = lv[i];
  }
  
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      mx[i][j] = max(mx[i][j - 1], lv[j]);

  cout << solve(0, n - 1);
}
