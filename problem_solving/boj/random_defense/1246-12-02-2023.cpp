#include <bits/stdc++.h>
using namespace std;

int a[1'002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++)
    cin >> a[i];
  sort(a, a + m);

  int pr = 0, tot = 0;
  for (int p = 1; p <= 1'000'000; p++) {
    int idx = lower_bound(a, a + m, p) - a;
    int cu = m - idx;
    cu = min(cu, n);
    if (tot < cu * p) {
      tot = cu * p;
      pr = p;
    }
  }
  cout << pr << ' ' << tot;
}
