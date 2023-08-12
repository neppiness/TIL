#include <bits/stdc++.h>
using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int n, m;
int dist[102][102][4]; // dist[x][y][dir]
char b[102][102];

queue<tuple<int, int, int>> q;
pair<int, int> c[2];

bool OOB(int x, int y) {
  return (x >= n || x < 0 || y >= m || y < 0);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(dist, 0x7f, sizeof(dist));

  cin >> m >> n;
  int cnt = 0;
  for (int i = 0; i < n; i++)
    cin >> b[i];
  
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (b[i][j] == 'C') c[cnt++] = {i, j};
  
  auto [x, y] = c[0];
  for (int dir = 0; dir < 4; dir++) {
    dist[x][y][dir] = 0;
    q.push({x, y, dir});
  }

  while (!q.empty()) {
    auto [cx, cy, cdir] = q.front(); q.pop();
    for (int ndir : {cdir, cdir + 1, cdir + 3}) {
      // 방향을 트는 경우
      if (ndir >= 4) ndir -= 4;
      int nx = cx + dx[ndir];
      int ny = cy + dy[ndir];
      int co = dist[cx][cy][cdir] + (cdir != ndir);
      if (OOB(nx, ny)) continue;
      if (dist[nx][ny][ndir] <= co) continue;
      if (b[nx][ny] == '*') continue;
      q.push({nx, ny, ndir});
      dist[nx][ny][ndir] = co;
    }
  }
  int ans = 0x7f7f7f7f;
  for (int dir = 0; dir < 4; dir++) {
    int cand = dist[c[1].first][c[1].second][dir];
    if (cand == -1) continue;
    ans = min(ans, cand);
  }
  cout << ans;
}