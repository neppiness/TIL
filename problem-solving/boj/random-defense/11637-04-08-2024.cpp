#include <bits/stdc++.h>
using namespace std;

string solve() {
  int n; cin >> n;
  int a[n + 2] = {};
  int sum = 0, mx = 0, count = 1, idx = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
    if (a[i] == mx) {
      count++;
    } else if (a[i] > mx) {
      count = 1;
      idx = i;
    }
    mx = max(mx, a[i]);
  }

  if (count > 1) {
    return "no winner";
  } else if (mx * 2 > sum) {
    return "majority winner " + to_string(idx);
  }
  return "minority winner " + to_string(idx);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--)
    cout << solve() << '\n';
}
