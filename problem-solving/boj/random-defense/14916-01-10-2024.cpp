#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int dp[100'002];

int solve(int x) {
  if (x < 0) return INF;
  int &ret = dp[x];
  if (ret != -1) return ret;
  if (x == 0) return ret = 0;

  return ret = min(solve(x - 2), solve(x - 5)) + 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(dp, -1, sizeof(dp));
  
  int n; cin >> n;
  int ans = solve(n);
  if (ans >= INF) ans = -1;
  cout << ans;
}
