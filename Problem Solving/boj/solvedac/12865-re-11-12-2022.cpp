#include <bits/stdc++.h>
using namespace std;

int n, k, w, v;
int dp[102][100002];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  for(int i = 1; i <= n; i++) {
    cin >> w >> v;

    for(int j = 0; j <= k; j++)
      dp[i][j] = dp[i - 1][j];

    for(int j = 0; j < k; j++) {
      if(w > k - j) continue;
      dp[i][j + w] = max(dp[i - 1][j] + v, dp[i - 1][j + w]);
    }
  }
  cout << dp[n][k];
}