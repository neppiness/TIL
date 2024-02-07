#include <bits/stdc++.h>
using namespace std;

int n, m, cnt;
bool vis[102][72];
int h[102][72];

int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};

bool oob(int x, int y) {
  return x >= n || x < 0 || y >= m || y < 0;
}

void bfs(int x, int y) {
  queue<pair<int, int>> q;
  q.push({x, y});
  vis[x][y] = 1;
  bool is_peak = 1;
  while (!q.empty()) {
    auto [cx, cy] = q.front(); q.pop();
    for (int dir = 0; dir < 8; dir++) {
      int nx = cx + dx[dir];
      int ny = cy + dy[dir];
      if (oob(nx, ny)) continue;
      if (h[nx][ny] != h[x][y]) {
        is_peak &= h[nx][ny] < h[x][y];
        continue;
      }
      if (vis[nx][ny]) continue;
      q.push({nx, ny});
      vis[nx][ny] = 1;
    }
  }
  cnt += is_peak;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n >> m;  
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> h[i][j];

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (!vis[i][j]) bfs(i, j);

  cout << cnt;  
}
