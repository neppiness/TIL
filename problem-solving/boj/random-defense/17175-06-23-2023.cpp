#include <bits/stdc++.h>
using namespace std;

const int kMod = 1e9 + 7;

int dp[52];

int solve(int x) {
  int &ret = dp[x];
  if (ret != -1) return ret;

  if (x < 2) return ret = 1;
  ret = 1;
  ret += solve(x - 2) + solve(x - 1);
  if (ret >= kMod) ret -= kMod;
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(dp, -1, sizeof(dp));
  int n; cin >> n;
  cout << solve(n);
}