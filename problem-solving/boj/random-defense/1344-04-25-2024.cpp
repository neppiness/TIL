#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[20][20];

ll comb(int n, int r) {
  ll &ret = dp[n][r];
  if (ret != -1) return ret;
  if (r == 0 || r == n) return ret = 1;
  return ret = comb(n - 1, r) + comb(n - 1, r - 1);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(dp, -1, sizeof(dp));

  cout.precision(9);
  cout << fixed;

  int n, m; cin >> n >> m;
  double a, b;

  for (int np : {0, 1, 4, 6, 8, 9, 10, 12, 14, 15, 16, 18}) {
    double tmp_a = comb(18, np);
    double tmp_b = comb(18, np);

    for (int i = 0; i < np; i++) {
      tmp_a *= ((double) n) / 100;
      tmp_b *= ((double) m) / 100;
    }

    for (int i = 0; i < 18 - np; i++) {
      tmp_a *= ((double) (100 - n)) / 100;
      tmp_b *= ((double) (100 - m)) / 100;
    }
    a += tmp_a; b += tmp_b;
  }
  cout << 1 - a * b;
}
