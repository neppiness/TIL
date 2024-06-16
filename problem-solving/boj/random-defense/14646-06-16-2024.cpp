#include <bits/stdc++.h>
using namespace std;

int cnt, ans;
bool st[100'002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 0; i < 2*n; i++) {
    int x; cin >> x;
    if (st[x]) {
      st[x] = 0;
      cnt--;
    } else {
      st[x] = 1;
      cnt++;
      ans = max(cnt, ans);
    }
  }
  cout << ans;
}
