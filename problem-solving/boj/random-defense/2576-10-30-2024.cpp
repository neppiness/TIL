#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n = 7;
  int sum = 0;
  int mx = 0x7f7f7f7f;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    if (x % 2 == 0) continue;
    sum += x;
    mx = min(x, mx);
  }
  if (sum == 0) {
    cout << -1 << '\n';
    return 0;
  }
  cout << sum << '\n' << mx;
}
