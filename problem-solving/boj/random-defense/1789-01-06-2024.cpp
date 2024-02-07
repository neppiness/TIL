#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll s; cin >> s;

  ll ans = 0;
  for (ll n = 1; 1; n++) {
    ll ss = n * (n + 1) / 2;   
    if (s < ss) break;
    ll alpha = s - ss;
    if (alpha > n) ans = max(ans, n + 1);
    else ans = max(ans, n);
  }
  cout << ans;
}
