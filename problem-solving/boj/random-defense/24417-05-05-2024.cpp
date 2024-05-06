#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1'000'000'007;

tuple<ll, ll, ll, ll> solve(int x) {
  if (x == 1) return {1, 1, 1, 0};

  auto [a, b, c, d] = solve(x / 2);
  ll e = (a*a + b*c) % MOD;
  ll f = (a*b + b*d) % MOD;
  ll g = (c*a + d*c) % MOD;
  ll h = (c*b + d*d) % MOD;
  if (x % 2) {
    ll i = (e + f) % MOD;
    ll j = e;
    ll k = (g + h) % MOD;
    ll l = g;
    return {i, j, k, l};
  }
  return {e, f, g, h};
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  auto [a, b, c, d] = solve(n);
  cout << c << ' ' << n - 2;
}
