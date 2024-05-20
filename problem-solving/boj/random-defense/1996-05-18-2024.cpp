#include <bits/stdc++.h>
using namespace std;

int n; 
char board[1002][1002];

int dx[] = {1, 0, -1, 0, 1, -1, 1, -1};
int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

bool oob(int x, int y) {
  return x >= n || x < 0 || y >= n || y < 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> board[i];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (board[i][j] != '.') {
        cout << '*';
        continue;
      }
      int cnt = 0;
      for (int dir = 0; dir < 8; dir++) {
        int nx = i + dx[dir];
        int ny = j + dy[dir];
        if (oob(nx, ny) || board[nx][ny] == '.') continue;
        cnt += board[nx][ny] - '0';
      }
      if (cnt >= 10) cout << 'M';
      else cout << cnt;
    }
    cout << '\n';
  }
}
