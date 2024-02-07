#include <bits/stdc++.h>
using namespace std;

int n; 
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

char b[1002][1002];

bool oob(int x, int y) {
  return x < 0 || x >= n || y < 0 || y >= n;
}

bool is_heart(int cx, int cy) {
  if (b[cx][cy] != '*') return 0;
  for (int dir = 0; dir < 4; dir++) {
    int nx = cx + dx[dir];
    int ny = cy + dy[dir];
    if (oob(nx, ny) || b[nx][ny] == '_') return 0;
  }
  return 1;
}

pair<int, int> heart() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (!is_heart(i, j)) continue;
      return {i, j};
    }
  }
  return {-1, -1};
}

int arm(int x, int y, int dir) {
  int len = 1;
  int nx = x + dx[dir], ny = y + dy[dir];
  while (!oob(nx, ny) && b[nx][ny] == '*') {
    len++;
    nx += dx[dir];
    ny += dy[dir];
  }
  return len;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> b[i];

  int x, y;
  tie(x, y) = heart();
  cout << x + 1 << ' ' << y + 1 << '\n';
  cout << arm(x, y - 1, 2) << ' ';
  cout << arm(x, y + 1, 0) << ' ';
  int w = arm(x + 1, y, 1);
  cout << w << ' ';
  cout << arm(x + w + 1, y - 1, 1) << ' ';
  cout << arm(x + w + 1, y + 1, 1);
}
