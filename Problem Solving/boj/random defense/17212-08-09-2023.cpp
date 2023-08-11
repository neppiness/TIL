#include <bits/stdc++.h>
using namespace std;

vector<int> coin = vector<int>({7, 5, 2, 1});
int dp[100'002];

int solve(int pr) {
  if (pr == 0) return 0;

  int &ret = dp[pr];
  if (ret != -1) return ret;

  ret = 0x7f7f7f7f;
  for (int co : coin) {
    if (pr - co < 0) continue;
    ret = min(ret, solve(pr - co) + 1);
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(dp, -1, sizeof(dp));
  int n; cin >> n;
  cout << solve(n);
}
