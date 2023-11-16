#include <bits/stdc++.h>
using namespace std;

int a[1'002];

void solve() {
  int n; cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];

  for (int i = 1; i <= n; i++)
    a[i] += a[i - 1];
  int ans = -1'000'000;
  for (int i = 1; i <= n; i++)
    for (int j = 0; j < i; j++)
      ans = max(ans, a[i] - a[j]);
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) solve();
}
