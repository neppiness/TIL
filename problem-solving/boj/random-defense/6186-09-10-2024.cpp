#include <bits/stdc++.h>
using namespace std;

int n, m; 
bool vis[102][102];
char b[102][102];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool oob(int x, int y) {
  return x >= n || x < 0 || y >= m || y < 0;
}

void bfs(int x, int y) {
  vis[x][y] = 1;
  queue<pair<int, int>> q;
  q.push({x, y});
  while (!q.empty()) {
    auto [cx, cy] = q.front(); q.pop();
    for (int dir = 0; dir < 4; dir++) {
      int nx = cx + dx[dir];
      int ny = cy + dy[dir];
      if (oob(nx, ny) || vis[nx][ny] || b[nx][ny] == '.') continue;
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
    cin >> b[i];

  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (vis[i][j] || b[i][j] == '.') continue;
      bfs(i, j);
      cnt++;
    }
  }
  cout << cnt;
}
