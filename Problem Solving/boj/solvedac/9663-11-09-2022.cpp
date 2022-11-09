#include <bits/stdc++.h>
using namespace std;

int n, cnt;
int b[17][17];

int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

bool oob(int x, int y) { return (x >= n || x < 0 || y >= n || y < 0); }

void act(int x, int y, int d) {
  b[x][y] += d;
  int nx, ny;
  for(int dir = 0; dir < 8; dir++) {
    nx = x, ny = y;
    while(1) {
      nx += dx[dir];
      ny += dy[dir];
      if(oob(nx, ny)) break;
      b[nx][ny] += d;
    }
  }
}

void solve(int idx, int lev) {
  if(lev == n) {
    cnt++;
    return;
  }

  for(; idx < n*n; idx++) {
    int i = idx / n;
    int j = idx % n;
    if(b[i][j]) continue;

    act(i, j, 1);
    solve(idx, lev + 1);
    act(i, j, -1);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  solve(0, 0);

  cout << cnt;
}