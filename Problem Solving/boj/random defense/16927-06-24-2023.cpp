#include <bits/stdc++.h>
using namespace std;

int n, m, r;
int a[302][302];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

pair<int, int> move(int x1, int y1, int x2, int y2, int x, int y) {
  int dir;
  if (x == x1 && y != y1) dir = 3;
  else if (y == y1 && x != x2) dir = 0;
  else if (x == x2 && y != y2) dir = 1;
  else dir = 2;
  return pair<int, int>(x + dx[dir], y + dy[dir]);
}

void rotate(int x1, int y1, int x2, int y2) {
  int tmp[302][302];
  for (int i = x1; i <= x2; i++)
    for (int j = y1; j <= y2; j++)
      tmp[i][j] = a[i][j];

  int len_x = x2 - x1;
  int len_y = y2 - y1;
  const int mod = 2*len_x + 2*len_y;
  int cyc = r % mod;

  int nx = x1, ny = y1;
  for (int i = 0; i < cyc; i++)
    tie(nx, ny) = move(x1, y1, x2, y2, nx, ny);
  
  int cx = x1, cy = y1;
  do {
    tmp[nx][ny] = a[cx][cy];
    tie(cx, cy) = move(x1, y1, x2, y2, cx, cy);
    tie(nx, ny) = move(x1, y1, x2, y2, nx, ny);
  } while (cx != x1 || cy != y1);

  for (int i = x1; i <= x2; i++)
    for (int j = y1; j <= y2; j++)
      a[i][j] = tmp[i][j];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> r;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> a[i][j];

  int x1 = 0, y1 = 0, x2 = n - 1, y2 = m - 1;
  while (x1 < x2 && y1 < y2) {
    rotate(x1, y1, x2, y2);
    x1++; x2--; y1++; y2--;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      cout << a[i][j] << ' ';
    cout << '\n';
  }
}