#include <bits/stdc++.h>
using namespace std;

int cnt, dir;
int n, m; 
bool vis[1002][1002];
bool is_done;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool oob(int x, int y) {
  return x > n || x < 1 || y > m || y < 1;
}

void solve(int x, int y) {
  vis[x][y] = 1;
  cnt--;
  if (cnt == 0) {
    cout << x << ' ' << y;
    return;
  }

  int nx = x + dx[dir];
  int ny = y + dy[dir];

  if (vis[nx][ny] || oob(nx, ny)) {
    dir = (dir + 1) % 4;
  }
  nx = x + dx[dir];
  ny = y + dy[dir];
  if (vis[nx][ny] || oob(nx, ny)) {
    cout << 0; return;
  }
  solve(nx, ny);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  cin >> cnt;
  solve(1, 1);
}
