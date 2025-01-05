#include <bits/stdc++.h>
using namespace std;

int a[3002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  sort(a, a + n);

  int mx = 0;
  int ans;
  for (int i = 1; i < n; i++) {
    int x = (a[i] + a[i - 1]) / 2;
    if (x == a[i] || x == a[i - 1]) continue;
    int d1 = abs(x - a[i]);
    int d2 = abs(x - a[i - 1]);
    int d = min(d1, d2);
    if (d <= mx) continue;
    mx = d;
    ans = x;
  }
  if (mx == 0) {
    cout << -1;
  } else {
    cout << ans;
  }
}
