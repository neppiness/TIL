#include <bits/stdc++.h>
using namespace std;

unordered_map< int, unordered_map<int, int> > dp;

int solve(int n, int k) {
  if (n == k || k == 0) return dp[n][k] = 1;
  int &ret = dp[n][k];
  if (ret) return ret;
  return ret = solve(n - 1, k) + solve(n - 1, k - 1);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  while (1) {
    cin >> n >> k;
    if (n == 0 && k == 0) break;
    cout << solve(n, k) << '\n';
    dp.clear();
  }
}
