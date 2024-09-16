#include <bits/stdc++.h>
using namespace std;

int ans[5];
char b[52][52];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> b[i];

  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < m - 1; j++) {
      int cnt = 0;
      if (b[i][j] == '#' || b[i + 1][j] == '#'
          || b[i][j + 1] == '#' || b[i + 1][j + 1] == '#') continue;
      cnt += (b[i][j] == 'X');
      cnt += (b[i + 1][j] == 'X');
      cnt += (b[i][j + 1] == 'X');
      cnt += (b[i + 1][j + 1] == 'X');
      ans[cnt]++;
    }
  }
  for (int i = 0; i < 5; i++)
    cout << ans[i] << '\n';
}
