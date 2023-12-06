#include <bits/stdc++.h>
using namespace std;

pair<int, int> a[102];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    int x, y; cin >> x >> y;
    a[i] = {x, y};
  }

  sort(a, a + n);

  int ans = 0;
  for (int i = 0; i < n; i++) {
    auto [ar, du] = a[i];
    ans = max(ar, ans);
    ans += du;
  }
  cout << ans;
}
