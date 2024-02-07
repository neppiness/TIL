#include <bits/stdc++.h>
using namespace std;

int n;
int mn[1002][1002], mx[1002][1002];
int dp[1002][1002];

int solve(int a, int b) {
  int &ret = dp[a][b];
  if (ret != -1) return ret;
  if (a == b) return ret = 0;
  
  ret = mx[a][b] - mn[a][b];
  for (int i = a; i < b; i++) {
    ret = max(ret, solve(a, i) + solve(i + 1, b));
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(dp, -1, sizeof(dp));

  cin >> n;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    mx[i][i] = mn[i][i] = x;
  }

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      mx[i][j] = max(mx[i][j - 1], mx[j][j]);
      mn[i][j] = min(mn[i][j - 1], mn[j][j]);
    }
  }
  cout << solve(0, n - 1);
}
