#include <bits/stdc++.h>
using namespace std;

char board[102][102];
char ans[102][102];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> board[i];

  for (int i = 0; i < n; i++)
    fill(ans[i], ans[i] + m, '.');

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (board[i][j] == '#') {
        ans[i][j] = '#';
        ans[i][j + 1] = '#';
        ans[i + 1][j] = '#';
        ans[i + 1][j + 1] = '#';
      }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << ans[i][j];
    }
    cout << '\n';
  }
}
