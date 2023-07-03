#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int kMod = 1e9 + 7;

ll dp[5002][2];

ll solve(int); // pre-declaration

ll solve(int x, bool is_wrapped) {
  if (x % 2) return 0;
  if (x == 2) return is_wrapped;

  ll &ret = dp[x][is_wrapped];
  if (ret != -1) return ret;

  ret = 0;
  int y = x;
  if (is_wrapped) {
    while (y != 2) {
      ret += solve(y - 2);
      ret %= kMod;
      y -= 2;
    }
  } else {
    while (y != 2) {
      ret += solve(x - y + 2) * solve(y - 2, 1);
      ret %= kMod;
      y -= 2;
    }
  }
  return ret;
}

ll solve(int x) {
  return (solve(x, 0) + solve(x, 1)) % kMod;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(dp, -1, sizeof(dp));

  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    cout << solve(n) << '\n';
  }
}