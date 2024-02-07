#include <bits/stdc++.h>
using namespace std;

int n; 
int dp[1002], a[1002];

int solve(int cur) {
  int &ret = dp[cur];
  if (ret != -1) return ret;

  ret = 0;
  for (int i = cur + 1; i < n; i++) {
    if (a[cur] <= a[i]) continue;
    ret = max(ret, solve(i));
  }
  return ret += a[cur];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(dp, -1, sizeof(dp));

  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  int ans = 0;
  for (int i = 0; i < n; i++)
    ans = max(ans, solve(i));
  cout << ans;
}
