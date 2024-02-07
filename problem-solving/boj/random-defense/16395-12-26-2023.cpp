#include <bits/stdc++.h>
using namespace std;

int dp[32][32];

int solve(int n, int k) {
  if (k == 0 || k == n) return 1;
  int &ret = dp[n][k];
  return ret = solve(n - 1, k - 1) + solve(n - 1, k);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 0; i < 30; i++) {
    for (int j = 0; j <= i; j++) {
      if (j == 0 || j == i) {
        dp[i][j] = 1;
      } else {
        dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
      }
    }
  }

  int n, k; cin >> n >> k;
  n--; k--; 
  cout << dp[n][k];
}
