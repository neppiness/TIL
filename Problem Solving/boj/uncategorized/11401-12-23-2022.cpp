#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int M = 1'000'000'007;

ll po(int x, int p) {
  if(p == 1) return x;
  ll mulhalf = po(x, p / 2);
  if(p % 2 == 0) return (mulhalf * mulhalf) % M;
  return (((x * mulhalf) % M) * mulhalf) % M;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, r; cin >> n >> r;
  if(n / 2 < r) r = n - r;

  ll ans = 1;
  for(int i = 0; i < r; i++) {
    ans *= (ll)(n - i);
    ans %= M;
    ans *= po(i + 1, M - 2);
    ans %= M;
  }
  cout << ans;
}