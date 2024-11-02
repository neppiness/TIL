#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int x, y; cin >> x >> y;
  int mul = x * y;
  int ans = mul / (4840 * 5);
  ans += (mul % (4840 * 5) != 0);
  cout << ans;
}
