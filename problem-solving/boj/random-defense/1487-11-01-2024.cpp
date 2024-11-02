#include <bits/stdc++.h>
using namespace std;
using ll = long long;

pair<int, int> a[52];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  ll mx = 0;
  for (int i = 0; i < n; i++) {
    ll pr, co; cin >> pr >> co;
    a[i] = {pr, co};
    mx = max(mx, pr);
  }
  
  ll sum_mx = 0;
  ll ans = 0;
  for (ll p = 0; p <= mx; p++) {
    ll sum = 0;
    for (int i = 0; i < n; i++) {
      auto [pr, co] = a[i];
      if (pr < p) continue;
      sum += max((ll)0, p - co);
    }
    if (sum > sum_mx) {
      ans = p;
      sum_mx = sum;
    }
  }
  cout << ans;
}
