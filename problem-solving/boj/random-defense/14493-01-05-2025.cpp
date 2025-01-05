#include <bits/stdc++.h>
using namespace std;

pair<int, int> a[50'002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    int x, y; cin >> x >> y;
    a[i] = {x, y};
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    auto [x, y] = a[i];
    int t = x + y;
    if (ans % t <= y) {
      ans += (y - (ans % t)) + 1;
    } else {
      ans++;
    }
  }
  cout << ans;
}
