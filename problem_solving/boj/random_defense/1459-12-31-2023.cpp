#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll x, y, w, s;
  cin >> x >> y >> w >> s;
  if (x < y) swap(x, y); // x가 항상 큰 수

  ll ans1 = w * x + w * y;
  ll ans2 = s * y + w * (x - y);
  ll tmp = min(ans1, ans2);

  ll ans = 0;
  if ((x + y) % 2) {
    ans += w;
    x--;
  }
  ans += x * s;
  cout << min(ans, tmp);
}
