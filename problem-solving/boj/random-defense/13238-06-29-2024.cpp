#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int ans = 0;
  int mn = 0x7f7f7f7f;
  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    mn = min(mn, x);
    ans = max(ans, x - mn);
  }
  cout << ans;
}
