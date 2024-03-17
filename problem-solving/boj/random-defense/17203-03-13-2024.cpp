#include <bits/stdc++.h>
using namespace std;

int a[1002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, q; cin >> n >> q;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  while (q--) {
    int ans = 0;
    int x, y; cin >> x >> y;
    for (int i = x; i < y; i++) {
      ans += abs(a[i] - a[i + 1]);
    }
    cout << ans << '\n';
  }
}
