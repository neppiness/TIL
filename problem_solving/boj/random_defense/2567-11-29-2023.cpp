#include <bits/stdc++.h>
using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool b[102][102];

bool oob(int x, int y) {
  return x < 0 || x >= 100 || y < 0 || y >= 100;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  while (n--) {
    int x, y; cin >> x >> y;
    for (int i = x; i < x + 10; i++)
      for (int j = y; j < y + 10; j++)
        b[i][j] = 1;
  }

  int cnt = 0;
  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 100; j++) {
      if (!b[i][j]) continue;
      for (int dir = 0; dir < 4; dir++) {
        int ni = i + dx[dir];
        int nj = j + dy[dir];
        cnt += (oob(ni, nj) || !b[ni][nj]);
      }
    }
  }
  cout << cnt;
}
