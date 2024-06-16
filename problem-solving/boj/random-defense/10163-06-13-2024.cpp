#include <bits/stdc++.h>
using namespace std;

int board[1002][1002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(board, -1, sizeof(board));

  int n; cin >> n;
  for (int k = 0; k < n; k++) {
    int x, y, dx, dy;
    cin >> x >> y >> dx >> dy;
    for (int i = x; i < x + dx; i++) {
      for (int j = y; j < y + dy; j++) {
        board[i][j] = k;
      }
    }
  }

  int cnt[102] = {};
  for (int i = 0; i <= 1000; i++) {
    for (int j = 0; j <= 1000; j++) {
      if (board[i][j] == -1) continue;
      cnt[board[i][j]]++;
    }
  }

  for (int i = 0; i < n; i++) {
    cout << cnt[i] << '\n';
  }
}
