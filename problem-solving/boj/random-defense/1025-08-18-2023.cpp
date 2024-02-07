#include <bits/stdc++.h>
using namespace std;

int n, m;
int ans = -1;
int board[11][11];

int dx[] = {1, 1, -1, -1};
int dy[] = {1, -1, 1, -1};

bool oob(int x, int y) {
  return x >= n || x < 0 || y >= m || y < 0;
}

bool isSqrtNo(int x) {
  int rn = sqrt(x);
  if (rn * rn == x) return 1;
  return (rn + 1) * (rn + 1) == x;
}

void checkForUpdate(int no) {
  if (!isSqrtNo(no)) return;
  ans = max(ans, no);
}

void solve(int x, int y) {
  for (int dir = 0; dir < 4; dir++)
    for (int a = 0; a < 9; a++)
      for (int b = 0; b < 9; b++) {
        if (a == 0 && b == 0) continue;
        int no = board[x][y];
        checkForUpdate(no);
        int nx = x + a * dx[dir];
        int ny = y + b * dy[dir];
        while (!oob(nx, ny)) {
          no *= 10;
          no += board[nx][ny];
          checkForUpdate(no);
          nx += a * dx[dir];
          ny += b * dy[dir];
        }
      }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    string s; cin >> s;
    for (int j = 0; j < m; j++)
      board[i][j] = s[j] - '0';
  }

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      solve(i, j);

  cout << ans;
}

