#include <bits/stdc++.h>
using namespace std;

pair<int, int> a[3];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int xx, yy; cin >> xx >> yy;
  for (int i = 0; i < 3; i++) {
    int x, y; cin >> x >> y;
    a[i] = {x, y};
  }
  sort(a, a + 3);
  int ans = 0x7f7f7f7f;
  do {
    double tot = 0;
    int cx = xx, cy = yy;
    for (int i = 0; i < 3; i++) {
      auto [nx, ny] = a[i];
      tot += sqrt((cx - nx) * (cx - nx) + (cy - ny) * (cy - ny));
      cx = nx; cy = ny;
    }
    ans = min(ans, (int) tot);
  } while (next_permutation(a, a + 3));
  cout << ans;
}
