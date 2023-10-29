#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;

  int min_p = 1002, min_e = 1002;
  while (m--) {
    int p, e; cin >> p >> e;
    min_p = min(p, min_p);
    min_e = min(e, min_e);
  }

  int ans = 100'002;
  int lim = n / 6 + 1;
  for (int i = 0; i <= lim; i++) {
    int tmp = min_p * i;
    tmp += max(0, n - i * 6) * min_e;
    ans = min(ans, tmp);
  }
  cout << ans;
}
