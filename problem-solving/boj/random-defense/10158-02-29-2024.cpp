#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int w, h, x, y;
  cin >> w >> h >> x >> y;
  int t; cin >> t;
  x += t; y += t;
  x %= (2 * w); y %= (2 * h);
  if (x > w) {
    x = 2*w - x;
  }
  if (y > h) {
    y = 2*h - y;
  }
  cout << x << ' ' << y;
}
