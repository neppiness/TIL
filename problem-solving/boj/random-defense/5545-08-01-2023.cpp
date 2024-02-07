#include <bits/stdc++.h>
using namespace std;

int a[102];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int cal, n, d, t;
  cin >> n >> d >> t;
  cin >> cal;

  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n, greater<int>());

  int ans = cal / d;
  for (int i = 0; i < n; i++) {
    cal += a[i];
    ans = max(ans, cal / (d + (i + 1) * t));
  }
  cout << ans;
}