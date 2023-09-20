#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n, m, w, h;
pair<int, int> st, en;
int dist[1002][1002];
int b[1002][1002];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool oob(int x, int y) {
  x--; y--;
  return x + w > n || x < 0 || y + h > m || y < 0;
}

bool is_blocked(int x, int y) {
  x--; y--;
  int ret = b[x + w][y + h] + b[x][y];
  ret -= b[x + w][y] + b[x][y + h];
  return ret;
}

int solve() {
  int x, y;
  cin >> x >> y; st = {x, y};
  cin >> x >> y; en = {x, y};

  memset(dist, -1, sizeof(dist));
  queue<pair<int, int>> q;
  q.push(st);
  dist[st.X][st.Y] = 0;
  while (!q.empty()) {
    auto [cx, cy] = q.front(); q.pop();
    if (en.X == cx && en.Y == cy) return dist[cx][cy];
    for (int dir = 0; dir < 4; dir++) {
      int nx = cx + dx[dir];
      int ny = cy + dy[dir];
      if (oob(nx, ny)) continue;
      if (dist[nx][ny] != -1) continue;
      if (is_blocked(nx, ny)) continue;
      dist[nx][ny] = dist[cx][cy] + 1;
      q.push({nx, ny});
    }
  }
  return -1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      cin >> b[i][j];

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      b[i][j] += b[i - 1][j];

  for (int j = 1; j <= m; j++)
    for (int i = 1; i <= n; i++)
      b[i][j] += b[i][j - 1];

  cin >> w >> h;
  cout << solve();
}
