#include <bits/stdc++.h>
using namespace std;
using ll = long long;

pair<ll, int> dp[1002][1002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;

  memset(dp, -1, sizeof(dp));

  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    dp[i][i] = {0, x};
  }

  ll ans = 0;
  for (int k = 1; k < n; k++) {
    for (int i = 0; i + k < n; i++) {
      pair<ll, int> &ret = dp[i][i + k];
      for (int j = i; j + 1 <= i + k; j++) {
        pair<ll, int> &a = dp[i][j];
        pair<ll, int> &b = dp[j + 1][i + k];
        ll tmpt = a.first + b.first + a.second + b.second;
        int tmpm = max(a.second, b.second);
        pair<ll, int> tmp = {tmpt, tmpm};
        ans = max(ans, tmpt);
        if (ret < tmp) ret = tmp;
      }
    }
  }
  cout << ans;
}
