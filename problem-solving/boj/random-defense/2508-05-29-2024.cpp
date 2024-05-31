#include <bits/stdc++.h>
using namespace std;

int n, m; 
char board[402][402];

bool oob(int x, int y) {
  return x >= n || x < 0 || y >= n || y < 0;
}

int solve() {
  cin >> n >> m;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    cin >> board[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (board[i][j] != 'o') continue;
      if (!oob(i + 1, j) && !oob(i - 1, j)) {
        cnt += ((board[i + 1][j] == '^') && (board[i - 1][j] == 'v'));
      }
      if (!oob(i, j + 1) && !oob(i, j - 1)) {
        cnt += ((board[i][j + 1] == '<') && (board[i][j - 1] == '>'));
      }
    }
  }
  return cnt;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    cout << solve() << '\n';
  }
}
