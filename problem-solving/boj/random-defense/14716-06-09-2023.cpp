#include <bits/stdc++.h>
using namespace std;

int n, m;
bool b[252][252];
bool vis[252][252];

int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};

queue<pair<int, int>> q;

bool OOB(int x, int y) {
  return (x >= n || x < 0 || y >= m || y < 0);
}

void Solve(int x, int y) {
  q.push({x, y});
  vis[x][y] = 1;

  while (!q.empty()) {
    auto [cx, cy] = q.front(); q.pop();
    for (int dir = 0; dir < 8; dir++) {
      int nx = cx + dx[dir];
      int ny = cy + dy[dir];
      if (OOB(nx, ny)) continue;
      if (vis[nx][ny] || !b[nx][ny]) continue;
      vis[nx][ny] = 1;
      q.push({nx, ny});
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> b[i][j];

  int cnt = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if (!b[i][j] || vis[i][j]) continue;
      cnt++; Solve(i, j);
    }

  cout << cnt;
}