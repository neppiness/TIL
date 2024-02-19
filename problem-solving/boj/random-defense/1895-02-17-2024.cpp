#include <bits/stdc++.h>
using namespace std;

int a[42][42];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> a[i][j];
  for (int i = 0; i < n - 2; i++) {
    for (int j = 0; j < m - 2; j++) {
      int b[9];
      int idx = 0;
      for (int ii = i; ii < i + 3; ii++)
        for (int jj = j; jj < j + 3; jj++)
          b[idx++] = a[ii][jj];
      sort(b, b + 9);
      a[i][j] = b[4];
    }
  }

  int lim; cin >> lim;
  int ans = 0;
  for (int i = 0; i < n - 2; i++)
    for (int j = 0; j < m - 2; j++)
      ans += (a[i][j] >= lim);
  cout << ans;
}
