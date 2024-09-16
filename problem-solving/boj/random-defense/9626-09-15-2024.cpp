#include <bits/stdc++.h>
using namespace std;

char C[] = {'#', '.'};

char b[12][12];
char ans[22][22];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  int u, l, r, d;
  cin >> u >> l >> r >> d;

  for (int i = 0; i < n; i++)
    cin >> b[i];
  
  int N = n + u + d;
  int M = m + l + r;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      ans[i][j] = C[(i + j) % 2];

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      ans[i + u][j + l] = b[i][j];

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++)
      cout << ans[i][j];
    cout << '\n';
  }

}
