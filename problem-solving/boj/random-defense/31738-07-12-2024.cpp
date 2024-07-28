#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll n, m; cin >> n >> m;
  if (n >= m) {
    cout << 0;
    return 0;
  }
  ll ans = 1;
  for (ll i = 2; i <= n; i++) {
    ans *= (i % m);
    ans %= m;
  }
  cout << ans;
}
