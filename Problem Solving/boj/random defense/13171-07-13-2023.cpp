#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;

ll ex(ll a, ll x) {
  if (x == 1) return a;
  ll exhalf = ex(a, x / 2);
  ll exhalfsq = (exhalf * exhalf) % MOD;
  if (x % 2) return (exhalfsq * a) % MOD;
  return exhalfsq;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll a, x; cin >> a >> x;
  cout << ex(a % MOD, x);
}