#include <bits/stdc++.h>
using namespace std;

int n, m, mx, ans;
vector<int> pl, mi;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    if (x > 0) pl.push_back(x);
    else mi.push_back(-x);
  }
  sort(pl.rbegin(), pl.rend());
  sort(mi.rbegin(), mi.rend());

  auto it = pl.begin();
  while (it != pl.end()) {
    ans += *it;
    mx = max(mx, *it);
    for (int i = 0; i < m; i++)
      if (++it == pl.end()) break;
  }

  it = mi.begin();
  while (it != mi.end()) {
    ans += *it;
    mx = max(mx, *it);
    for (int i = 0; i < m; i++)
      if (++it == mi.end()) break;
  }
  ans *= 2; ans -= mx;
  cout << ans;
}