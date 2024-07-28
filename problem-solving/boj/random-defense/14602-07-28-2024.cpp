#include <bits/stdc++.h>
using namespace std;

int b[32][32];
int a[902];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m, k, w;
  cin >> n >> m >> k >> w;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> b[i][j];

  for (int i = 0; i < n - w + 1; i++) {
    for (int j = 0; j < m - w + 1; j++) {
      int cnt = 0;
      for (int ii = i; ii < i + w; ii++) {
        for (int jj = j; jj < j + w; jj++) {
          a[cnt++] = b[ii][jj];
        }
      }
      sort(a, a + cnt);
      cout << a[cnt / 2] << ' ';
    }
    cout << '\n';
  }
}
