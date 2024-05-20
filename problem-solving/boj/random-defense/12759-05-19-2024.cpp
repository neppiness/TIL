#include <bits/stdc++.h>
using namespace std;

int n, b[4][4];
int dx[] = {1, 0, 1, -1};
int dy[] = {0, 1, 1, 1};

bool oob(int x, int y) {
  return x > 3 || x < 1 || y > 3 || y < 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  int x, y;
  while (cin >> x >> y) {
    b[x][y] = n;    
    for (int dir = 0; dir < 4; dir++) {
      int cnt = 0;
      for (int d = -2; d <= 2; d++) {
        int nx = x + d * dx[dir];
        int ny = y + d * dy[dir];
        if (oob(nx, ny)) continue;
        cnt += (b[nx][ny] == n);
      }
      if (cnt < 3) continue;
      cout << n;
      return 0;
    }
    if (n == 2) n = 1;
    else n = 2;
  }
  cout << 0;
}
