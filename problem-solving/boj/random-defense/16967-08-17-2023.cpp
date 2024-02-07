#include <bits/stdc++.h>
using namespace std;

int a[602][602];
int n, m, x, y;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> x >> y;
  for (int i = 0; i < n + x; i++)
    for (int j = 0; j < m + y; j++)
      cin >> a[i][j];

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      a[i + x][j + y] -= a[i][j];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      cout << a[i][j] << ' '; 
    cout << '\n';
  }
}
