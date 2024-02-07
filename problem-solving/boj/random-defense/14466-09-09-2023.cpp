#include <bits/stdc++.h>
using namespace std;

int n, k, r, id;
int comp[102][102];
vector<pair<int, int>> cow;
bool is_blocked[102][102][4]; // is_blocked[x][y][dir]

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool oob(int x, int y) {
  return x < 0 || x >= n || y < 0 || y >= n;
}

void bfs(int x, int y) {
  queue<pair<int, int>> q;
  comp[x][y] = ++id;
  q.push({x, y});
  while (!q.empty()) {
    auto [cx, cy] = q.front(); q.pop();
    for (int dir = 0; dir < 4; dir++) {
      int nx = cx + dx[dir];
      int ny = cy + dy[dir];
      if (oob(nx, ny)) continue;
      if (comp[nx][ny]) continue;
      if (is_blocked[cx][cy][dir]) continue;
      comp[nx][ny] = id;
      q.push({nx, ny});
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k >> r;
  while (r--) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1--; y1--; x2--; y2--;
    int dir = 0;
    while (1) {
      int nx = x1 + dx[dir];
      int ny = y1 + dy[dir];
      if (nx == x2 && ny == y2) break;
      dir++;
    }
    int inv_dir = (dir + 2) % 4;
    is_blocked[x1][y1][dir] = 1;
    is_blocked[x2][y2][inv_dir] = 1;
  }

  while (k--) {
    int x, y;
    cin >> x >> y;
    x--; y--;
    cow.push_back({x, y});
  }

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (!comp[i][j]) bfs(i, j);

  int cnt = 0;
  for (int i = 0; i < cow.size(); i++) {
    auto [cx, cy] = cow[i];
    for (int j = i + 1; j < cow.size(); j++) {
      auto [nx, ny] = cow[j];
      cnt += (comp[cx][cy] != comp[nx][ny]);
    }
  }
  cout << cnt;
}
