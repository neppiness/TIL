#include <bits/stdc++.h>
using namespace std;

int n, m, t;
char b[102][102];
int dist[102][102];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

queue<pair<int, int>> q;

int ans = 0x7f7f7f7f;

bool OOB(int x, int y) {
  return (x >= n || x < 0 || y >= m || y < 0);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(dist, -1, sizeof(dist));

  cin >> n >> m >> t;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> b[i][j];

  dist[0][0] = 0;
  q.push({0, 0});

  while (!q.empty()) {
    auto [cx, cy] = q.front(); q.pop();
    for (int dir = 0; dir < 4; dir++) {
      int nx = cx + dx[dir];
      int ny = cy + dy[dir];
      if (OOB(nx, ny) || b[nx][ny] == '1') continue;
      if (dist[nx][ny] != -1) continue;
      dist[nx][ny] = dist[cx][cy] + 1;
      if (b[nx][ny] == '2') {
        ans = dist[nx][ny];
        ans += (abs(n - 1 - nx) + abs(m - 1 - ny));
      }
      q.push({nx, ny});
    }
  }

  if (dist[n - 1][m - 1] != -1) ans = min(ans, dist[n - 1][m - 1]);
  if (ans > t) { cout << "Fail"; return 0; }
  cout << ans;
}