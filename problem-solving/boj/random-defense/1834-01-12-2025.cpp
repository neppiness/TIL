#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll a; cin >> a;
  ll ans = 0;
  for (ll i = 1; i < a; i++) {
    ans += (i * a + i);
  }
  cout << ans;
}
