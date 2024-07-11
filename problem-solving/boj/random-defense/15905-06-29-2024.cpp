#include <bits/stdc++.h>
using namespace std;

pair<int, int> a[68];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    int x, y; cin >> x >> y;
    a[i] = {-x, y};
  }
  sort(a, a + n);

  int no = a[4].first;
  int ans = 0;
  for (int i = 5; i < n; i++) {
    int nno = a[i].first;
    if (no == nno) {
      ans++;
      continue;
    }
    break;
  }
  cout << ans;
}
