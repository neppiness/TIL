#include <bits/stdc++.h>
using namespace std;

int b[1026][1026];
int n, m;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      cin >> b[i][j];


  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      b[i][j] += b[i][j - 1];

  for (int j = 1; j <= m; j++)
    for (int i = 1; i <= n; i++)
      b[i][j] += b[i - 1][j];

  int q; cin >> q;
  while (q--) {
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    cout << b[r2][c2] + b[r1 - 1][c1 - 1] - b[r2][c1 - 1] - b[r1 - 1][c2] << '\n';
  }
}
