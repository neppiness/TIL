#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  int ans = 0;
  int cur = 0;
  while (n--) {
    int x; cin >> x;
    if (cur + x > m) {
      ans++;
      cur = x;
    } else {
      cur += x;
    }
  }
  cout << ans + (cur != 0);
}
