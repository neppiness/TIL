#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int prv; cin >> prv;
  int ans = 0;
  int h = 0;
  while (--n) {
    int cur; cin >> cur;
    if (cur > prv) {
      h += cur - prv;
      ans = max(h, ans);
    } else {
      h = 0;
    }
    prv = cur;
  }
  cout << ans;
}
