#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int a[200'002];
  int n; cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  int ans = 0;
  int mn = 0x7f7f7f7f;
  for (int i = 0; i < n; i++) {
    mn = min(mn, a[i]);
    ans = max(ans, a[i] - mn);
  }
  cout << ans;
}
