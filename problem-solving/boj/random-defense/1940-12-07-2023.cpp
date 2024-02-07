#include <bits/stdc++.h>
using namespace std;

int a[15'002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  sort(a, a + n);

  int en = n - 1;
  int ans = 0;
  for (int st = 0; st < n; st++) {
    while (st < en && a[st] + a[en] > m) en--;
    if (st >= en) break;
    ans += (a[st] + a[en] == m);
  }
  cout << ans;
}
