#include <bits/stdc++.h>
using namespace std;

int n, m;
int b[1002][1002];  // x, y, 지팡이 사용 여부
int dist[1002][1002][2];

queue<tuple<int, int, bool>> q;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool oob(int x, int y) {
  return x >= n || x < 0 || y >= m || y < 0;
}

int solve() {
  while (!q.empty()) {
    auto [cx, cy, st] = q.front(); q.pop();
    for (int dir = 0; dir < 4; dir++) {
      int nx = cx + dx[dir];
      int ny = cy + dy[dir];
      if (oob(nx, ny)) continue;
      if (dist[nx][ny][st] != -1) continue;
      if (b[nx][ny] == 2) return dist[cx][cy][st] + 1;
      if (b[nx][ny]) {
        if (st) continue;
        dist[nx][ny][1] = dist[cx][cy][st] + 1;
        q.push({nx, ny, 1});
        continue;
      }
      dist[nx][ny][st] = dist[cx][cy][st] + 1;
      q.push({nx, ny, st});
    }
  }
  return -1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(dist, -1, sizeof(dist));

  cin >> n >> m;
  int x, y; cin >> x >> y;

  q.push({x - 1, y - 1, 0});
  dist[x - 1][y - 1][0] = 0;

  cin >> x >> y;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> b[i][j];

  b[x - 1][y - 1] = 2; // 탈출구
  cout << solve();
}