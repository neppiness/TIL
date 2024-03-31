#include <bits/stdc++.h>
using namespace std;

int n, m; 
int a[100'002];

int solve() {
  int st, en; cin >> st >> en;
  if (st > en) swap(st, en);
  auto lb = lower_bound(a, a + n, st);
  auto ub = upper_bound(a, a + n, en);
  return ub - lb;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a, a + n);

  while (m--) {
    cout << solve() << '\n';
  }
}
