#include <bits/stdc++.h>
using namespace std;

int n;

void solve() {
  int x1, y1, r1, x2, y2, r2;
  cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
  int c = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
  int rm = (r1 - r2) * (r1 - r2);
  int rp = (r1 + r2) * (r1 + r2);

  if (c == 0 && r1 == r2) {
    if (r1) cout << -1;
    else cout << 1;
  } else if (c < rm) cout << 0;
  else if (c == rm || c == rp) cout << 1;
  else if (c < rp) cout << 2;
  else cout << 0;
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) solve();
}