#include <bits/stdc++.h>
using namespace std;

int a[1002][1002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m, k; cin >> n >> m >> k;

  for (int i = 0; i < n; i++)
    a[i][0] = i + 1;
  for (int j = 0; j < m; j++)
    a[0][j] = j + 1;

  for (int i = 1; i < n; i++)
    for (int j = 1; j < m; j++)
      a[i][j] = max(a[i - 1][j], a[i][j - 1]) + 1;

  if (a[n - 1][m - 1] > k) {
    cout << "NO";
  } else {
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++)
        cout << a[i][j] << ' ';
      cout << '\n';
    }
  }
}
