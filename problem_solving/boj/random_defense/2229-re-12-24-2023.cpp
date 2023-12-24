#include <bits/stdc++.h>
using namespace std;

int dp[1002][1002];
int mn[1002][1002], mx[1002][1002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    mn[i][i] = mx[i][i] = x;
  }

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      mx[i][j] = max(mx[i][j - 1], mx[j][j]);
      mn[i][j] = min(mn[i][j - 1], mn[j][j]);
    }
  }

  for (int k = 0; k < n; k++) {
    for (int i = 0; i + k < n; i++) {
      dp[i][i + k] = mx[i][i + k] - mn[i][i + k];
      for (int j = i; j < i + k; j++) {
        dp[i][i + k] = max(dp[i][i + k], dp[i][j] + dp[j + 1][i + k]);
      }
    }
  }
  cout << dp[0][n - 1];
}
