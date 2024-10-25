#include <bits/stdc++.h>
using namespace std;

int b[102][102];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        cin >> b[i][j];
    int tot = 0;
    for (int j = 0; j < m; j++) {
      int cur = n - 1;
      for (int i = n - 1; i >= 0; i--) {
        if (!b[i][j]) continue;
        tot += cur - i;
        cur--;
      }
    }
    cout << tot << '\n';
  }
}
