#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int x, y, r; cin >> x >> y >> r;

  int lx = x - r;
  int rx = x + r;

  int a = 0, b = 0;
  while (n--) {
    int c; cin >> c;
    a += (c > lx && c < rx);
    b += (c == lx || c == rx);
  }
  cout << a << ' ' << b;
}
