#include <bits/stdc++.h>
using namespace std;

int dp[1002];

int gcd(int a, int b) {
  if (a % b == 0) {
    return b;
  }
  return gcd(b, a % b);
}

int solve(int x) {
  int &ret = dp[x];
  if (ret != -1) return ret;

  ret = solve(x - 1);
  for (int i = 1; i <= x; i++) {
    int g = gcd(i, x);
    ret += (g == 1);
  }
  for (int j = 1; j <= x; j++) {
    int g = gcd(x, j);
    ret += (g == 1);
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
   
  memset(dp, -1, sizeof(dp));
  dp[0] = 0;
  dp[1] = 3;

  int t; cin >> t;
  while (t--) {
    int x; cin >> x;
    cout << solve(x) << '\n';
  }
}
