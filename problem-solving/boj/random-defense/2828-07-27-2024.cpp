#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m, k; cin >> n >> m >> k;
  int st = 1, en = m;
  int ans = 0;
  while (k--) {
    int x; cin >> x;
    if (st <= x && x <= en) continue;
    if (st > x) {
      int d = st - x;
      ans += d;
      st -= d; en -= d;
    } else {
      int d = x - en;
      ans += d;
      st += d; en += d;
    }
  }
  cout << ans;
}
