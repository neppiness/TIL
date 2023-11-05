#include <bits/stdc++.h>
using namespace std;

int a[102];

tuple<int, int, int> solve() {
  int n; cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a, a + n);
  int gap = 0;
  for (int i = 1; i < n; i++) {
    gap = max(gap, a[i] - a[i - 1]);
  }
  return {a[n - 1], a[0], gap};
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Class " << i << '\n';
    int mx, mn, gap;
    tie(mx, mn, gap) = solve();
    cout << "Max " << mx << ", ";
    cout << "Min " << mn << ", ";
    cout << "Largest gap " << gap << '\n';
  }
}
