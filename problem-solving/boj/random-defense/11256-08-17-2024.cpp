#include <bits/stdc++.h>
using namespace std;

int cnt[1002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
      int r, c; cin >> r >> c;
      cnt[i] = r * c;
    }
    sort(cnt, cnt + m, greater<int>());
    int i = 0;
    while (n > 0) {
      n -= cnt[i++];
    }
    cout << i << '\n';
  }
}
