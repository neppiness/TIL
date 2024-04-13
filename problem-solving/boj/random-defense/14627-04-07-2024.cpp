#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int s, c;
ll a[1'000'002];

bool solve(ll x) {
  ll sum = 0;
  for (int i = 0; i < s; i++) {
    sum += a[i] / x;
  }
  return sum >= c;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> s >> c;
  for (int i = 0; i < s; i++)
    cin >> a[i];

  ll st = 0, en = 1'000'000'002;
  while (st < en) {
    ll mid = (st + en) / 2 + 1;
    if (solve(mid)) {
      st = mid;
    } else {
      en = mid - 1;
    }
  }

  ll ans = 0;
  for (int i = 0; i < s; i++)
    ans += a[i];
  ans -= st * c;
  cout << ans;
}
