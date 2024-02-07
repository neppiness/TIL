#include <bits/stdc++.h>
using namespace std;

int n; 
pair<int, int> a[1002];

bool solve(int st) {
  for (int i = 0; i < n; i++) {
    if (st > a[i].first) return 0;
    st += a[i].second - a[i].first;
  }
  return 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  for (int i = 0; i < n; i++) {
    int t, en; cin >> t >> en;
    int st = en - t;
    a[i] = {st, en};
  }
  sort(a, a + n);

  int st = 0, en = 1'000'002;
  while (st < en) {
    int mid = (st + en) / 2 + 1;
    if (solve(mid)) st = mid;
    else en = mid - 1;
  }
  if (solve(st)) cout << st;
  else cout << -1;
}
