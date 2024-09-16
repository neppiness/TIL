#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
bool board[32][32];
ll mx[32][32];

int dx[] = {-1, 0};
int dy[] = {0, -1};

bool oob(int x, int y) {
  return x < 0 || x >= n || y < 0 || y >= n;
}

ll solve(int x, int y) {
  ll &ret = mx[x][y];
  if (ret != -1) return ret;
  if (x == 0 && y == 0) return board[0][0];

  ret = 0;
  for (int dir = 0; dir < 2; dir++) {
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if (oob(nx, ny)) continue;
    ret = max(ret, solve(nx, ny) * 2 + board[x][y]);
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(mx, -1, sizeof(mx));

  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> board[i][j];
  cout << solve(n - 1, n - 1);
}
