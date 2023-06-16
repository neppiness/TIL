#include <bits/stdc++.h>
using namespace std;

int n, t;
int dp[2][10002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> t;
  for (int i = 1; i <= n; i++) {
    int k, s; cin >> k >> s;
    for (int j = 0; j <= t; j++)
      dp[i % 2][j] = dp[(i - 1) % 2][j];

    for (int j = 0; j <= t; j++) {
      if (j + k > t) continue;
      dp[i % 2][j + k] = max(dp[i % 2][j + k], dp[(i - 1) % 2][j] + s);
    }
  }

  int *mxpt = max_element(dp[n % 2], dp[n % 2] + t + 1);
  cout << *mxpt;
}