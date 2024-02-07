#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  ll ans = 0;
  
  int x; cin >> x;
  // i를 약수로 갖는 경우: (x / i)가지
  int i = 1;
  for (; i * i <= x; i++)
    ans += (x / i) * i;
  i--;
  i = x / i;

  if (i == 1)
    ans += (x * (x + 1)) / 2 - 1;

  while (i > 1) {
    ll st = x / i, en = x / (i - 1);
    // st 초과, en 이하의 범위에 i - 1개의 수가 있음.
    ans += (en * (en + 1) / 2 - st * (st + 1) / 2) * (i - 1);
    i--;
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) solve();
}