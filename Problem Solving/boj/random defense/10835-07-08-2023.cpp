#include <bits/stdc++.h>
using namespace std;

int n;
int a[2002], b[2002];
int dp[2002][2002];

int solve(int i, int j) {
  if (i == n || j == n) return 0;
  int &ret = dp[i][j];
  if (ret != -1) return ret;

  ret = max(ret, solve(i + 1, j));
  ret = max(ret, solve(i + 1, j + 1));
  if (a[i] > b[j]) {
    ret = max(ret, b[j] + solve(i, j + 1));
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(dp, -1, sizeof(dp));

  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
    cin >> b[i];
  
  cout << solve(0, 0);
}