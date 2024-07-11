#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1'000'000'007;

ll pow(int a, int b) { // a^b
  if (b == 0) return 1;
  ll x = pow(a, b / 2);
  ll sq = (x * x) % MOD;
  return b % 2 ? (a * sq) % MOD : sq;
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  // m ^ n - (m - 1) ^ n
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    sum += (pow(m, i) * pow(m - 1, n - 1 - i)) % MOD;
    sum %= MOD;
  }
  cout << sum;
}
