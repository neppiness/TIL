#include <bits/stdc++.h>
using namespace std;

int n, m; 

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool vis[5002][5002];

bool oob(int x, int y) {
  return x < 0 || x >= n || y < 0 || y >= m;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> m >> n;
  int cx = 0; int cy = 0;

  int dir = 0;
  while (1) {
    vis[cx][cy] = 1;
    int nx = cx + dx[dir];
    int ny = cy + dy[dir];
    if (!oob(nx, ny) && !vis[nx][ny]) {
      cx = nx; cy = ny;
      continue;
    }
    dir = (dir + 1) % 4;
    nx = cx + dx[dir]; ny = cy + dy[dir];
    if (!oob(nx, ny) && !vis[nx][ny]) {
      cx = nx; cy = ny;
      continue;
    }
    dir = (dir + 1) % 4;
    nx = cx + dx[dir]; ny = cy + dy[dir];
    if (!oob(nx, ny) && !vis[nx][ny]) {
      cx = nx; cy = ny;
      continue;
    }
    dir = (dir + 1) % 4;
    nx = cx + dx[dir]; ny = cy + dy[dir];
    if (!oob(nx, ny) && !vis[nx][ny]) {
      cx = nx; cy = ny;
      continue;
    }
    cout << cy << ' ' << cx << '\n';
    return 0;
  }
}
