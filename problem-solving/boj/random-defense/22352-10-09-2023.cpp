#include <bits/stdc++.h>
using namespace std;

int n, m;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int a[32][32], b[32][32];
int tmp[32][32];

bool oob(int x, int y) {
  return x >= n || x < 0 || y >= m || y < 0;
}

bool solve(int x, int y) {
  int injected_val = b[x][y];
  int original_val = a[x][y];
  bool vis[32][32] = {};

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      tmp[i][j] = a[i][j];

  queue<pair<int, int>> q;
  vis[x][y] = 1;
  tmp[x][y] = injected_val;
  q.push({x, y});

  while (!q.empty()) {
    auto [cx, cy] = q.front(); q.pop();
    for (int dir = 0; dir < 4; dir++) {
      int nx = cx + dx[dir];
      int ny = cy + dy[dir];
      if (oob(nx, ny) || vis[nx][ny]) continue;
      if (tmp[nx][ny] != original_val) continue;
      tmp[nx][ny] = injected_val;
      vis[nx][ny] = 1;
      q.push({nx, ny});
    }
  }

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (b[i][j] != tmp[i][j])
        return 0;
  return 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> a[i][j];

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> b[i][j];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!solve(i, j)) continue;
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
}
