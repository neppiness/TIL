#include <bits/stdc++.h>
using namespace std;

int a[200'002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a, a + n);
  while (m--) {
    int x; cin >> x;
    auto it = lower_bound(a, a + n, x);
    int idx = it - a;
    if (idx >= n || a[idx] != x) cout << -1 << '\n';
    else cout << idx << '\n';
  }
}
