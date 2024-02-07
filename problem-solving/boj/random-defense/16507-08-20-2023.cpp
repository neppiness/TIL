#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m, k;
ll b[1002][1002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      cin >> b[i][j];
  
  for (int j = 1; j <= m; j++)
    for (int i = 1; i <= n; i++)
      b[i][j] += b[i - 1][j];

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      b[i][j] += b[i][j - 1];

  while (k--) {
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    ll tot = b[r2][c2] + b[r1 - 1][c1 - 1] - b[r1 - 1][c2] - b[r2][c1 - 1];
    int div = (r2 - r1 + 1) * (c2 - c1 + 1);
    cout << tot / div << '\n';
  }
}
