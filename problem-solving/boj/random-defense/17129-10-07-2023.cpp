#include <bits/stdc++.h>
using namespace std;

int n, m;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

char b[3002][3002];
int dist[3002][3002];

bool oob(int x, int y) {
  return x >= n || x < 0 || y >= m || y < 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  memset(dist, -1, sizeof(dist));
  queue<pair<int, int>> q;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> b[i][j];
      if (b[i][j] != '2') continue;
      q.push({i, j});
      dist[i][j] = 0;
    }
  
  while (!q.empty()) {
    auto [cx, cy] = q.front(); q.pop();
    for (int dir = 0; dir < 4; dir++) {
      int nx = cx + dx[dir];
      int ny = cy + dy[dir];
      if (oob(nx, ny)) continue;
      if (dist[nx][ny] != -1) continue;
      if (b[nx][ny] == '1') continue;
      q.push({nx, ny});
      dist[nx][ny] = dist[cx][cy] + 1;
      if (b[nx][ny] == '0') continue;
      cout << "TAK" << '\n';
      cout << dist[nx][ny];
      return 0;
    }
  }
  cout << "NIE";
}
