#include <bits/stdc++.h>
using namespace std;

char board[10][10];

int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};

bool oob(int x, int y) {
  return x >= 8 || x < 0 || y >= 8 || y < 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 0; i < 8; i++)
    cin >> board[i];

  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (board[i][j] != '*') continue;
      int cx = i, cy = j;
      for (int dir = 0; dir < 8; dir++) {
        int nx = cx + dx[dir];
        int ny = cy + dy[dir];
        while (!oob(nx, ny)) {
          if (board[nx][ny] == '*') {
            cout << "invalid";
            return 0;
          }
          nx += dx[dir];
          ny += dy[dir];
        }
      }
    }
  }
  cout << "valid";
}
