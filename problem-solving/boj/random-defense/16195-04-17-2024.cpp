#include <bits/stdc++.h>
using namespace std;

const int MOD = 1'000'000'009;
int dp[1002][1002];

int solve(int x, int picked) { // picked개 수로 x를 만드는 경우의 수
  if (picked == 0) {
    return (x == 0);
  }

  int &ret = dp[x][picked];
  if (ret != -1) return ret;
  ret = 0;
  for (int diff : {1, 2, 3}) {
    if (x - diff < 0) continue;
    ret += solve(x - diff, picked - 1);
    ret %= MOD;
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(dp, -1, sizeof(dp));

  int t; cin >> t;
  while (t--) {
    int n, m; cin >> n >> m;
    int ans = 0;
    for (int i = 0; i <= m; i++) {
      ans += solve(n, i);
      ans %= MOD;
    }
    cout << ans << '\n';
  }
}
