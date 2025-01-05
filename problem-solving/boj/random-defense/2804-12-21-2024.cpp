#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string a, b; cin >> a >> b;
  int n = a.size();
  int m = b.size();

  int x = -1;
  int y = 0;
  for (; y < m; y++) {
    x = b.find(a[y]);
    if (x == -1) continue;
    break;
  }
  for (int i = 0; i < m; i++) {
    if (i == x) {
      cout << a << '\n';
      continue;
    }
    for (int j = 0; j < n; j++) {
      if (j == y) cout << b[i];
      else cout << '.';
    }
    cout << '\n';
  }
}
