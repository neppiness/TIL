#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1'000'000'007;

ll pi(ll n) {
  if(n == 1 || n == 2) return 1;
  if(n == 3) return 2;
  ll ans = 0;

  if(n % 2 == 0) {
    ll pi_n_1 = pi(n / 2 - 1);
    ll pi_n = pi(n / 2);
    ans += pi_n;
    ans *= ((pi_n + 2*pi_n_1) % MOD);
  } else {
    ll pi_n_1 = pi(n / 2 + 1);
    ll pi_n = pi(n / 2);
    ans += (pi_n_1 * pi_n_1) % MOD;
    ans += (pi_n * pi_n) % MOD;
  }
  return ans % MOD;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  ll N; cin >> N;
  cout << pi(N);
}
