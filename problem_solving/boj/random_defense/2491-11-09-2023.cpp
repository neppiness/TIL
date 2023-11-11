#include <bits/stdc++.h>
using namespace std;

int n;
int a[100'002];
int asc_dp[100'002];
int dsc_dp[100'002];

int solve(int idx, bool is_asc) {
  int* dp = dsc_dp;
  if (is_asc) {
    dp = asc_dp;
  }

  int &ret = dp[idx];
  if (ret != -1) return ret;

  ret = 1;
  if (idx == n - 1) return ret;
  if (is_asc && a[idx + 1] >= a[idx]) return ret += solve(idx + 1, 1);
  if (!is_asc && a[idx + 1] <= a[idx]) return ret += solve(idx + 1, 0);
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(asc_dp, -1, sizeof(asc_dp));
  memset(dsc_dp, -1, sizeof(dsc_dp));

  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  int ans = 0;
  for (int i = 0; i < n; i++)
    ans = max(ans, solve(i, 0));

  for (int i = 0; i < n; i++)
    ans = max(ans, solve(i, 1));

  cout << ans;
}
