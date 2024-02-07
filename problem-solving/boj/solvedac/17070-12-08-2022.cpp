#include <bits/stdc++.h>
using namespace std;

bool b[18][18];
int n, cnt;
int dx[] = {0, 1, 1};
int dy[] = {1, 1, 0};

bool oob(int x, int y) { return (x >= n || x < 0 || y >= n || y < 0); }

bool chkwall(int x, int y, int dir) {
  if(dir != 1) return (b[x + dx[dir]][y + dy[dir]]);
  return (b[x + 1][y + 1] || b[x + 1][y] || b[x][y + 1]);
}

void solve(int cx, int cy, int cdir) {
  if(cx == n - 1 && cy == n - 1) {
    cnt++;
    return;
  }
  for(int d = -1; d <= 1; d++) {
    int ndir = cdir + d;
    if(ndir > 2 || ndir < 0) continue;
    int nx = cx + dx[ndir];
    int ny = cy + dy[ndir];
    if(oob(nx, ny)) continue;
    if(chkwall(cx, cy, ndir)) continue;
    solve(nx, ny, ndir);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      cin >> b[i][j];

  solve(0, 1, 0);
  cout << cnt;
}