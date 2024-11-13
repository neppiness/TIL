#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int st; cin >> st;
  int en;
  for (int i = 1; i < n; i++)
    cin >> en;

  st--; en--;
  for (int i = 0; i < n - 3; i++) {
    if (st > en) st--;
    else en--;
  }
  int ans = max(st, en);
  cout << ans;
}
