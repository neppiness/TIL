#include <bits/stdc++.h>
using namespace std;

int m, n, h;
int b[102][102][102];
int day[102][102][102];

int dx[] = {1, 0, -1, 0, 0, 0};
int dy[] = {0, 1, 0, -1, 0, 0};
int dz[] = {0, 0, 0, 0, -1, 1};

queue<tuple<int, int, int>> q;

int bfs() {
  int mx = 0;
  int cx, cy, cz;
  int nx, ny, nz;
  while(!q.empty()) {
    tie(cx, cy, cz) = q.front(); q.pop();
    for(int dir = 0; dir < 6; dir++) {
      nx = cx + dx[dir];
      ny = cy + dy[dir];
      nz = cz + dz[dir];
      if(nx >= n || nx < 0) continue;
      if(ny >= m || ny < 0) continue;
      if(nz >= h || nz < 0) continue;
      if(day[nx][ny][nz] != -1) continue;
      if(b[nx][ny][nz] == -1) continue;
      if(b[nx][ny][nz] == 0) {
        day[nx][ny][nz] = day[cx][cy][cz] + 1;
        b[nx][ny][nz] = 1;
        mx = max(mx, day[nx][ny][nz]);
      }
      q.push({nx, ny, nz});
    }
  }
  for(int k = 0; k < h; k++)
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
        if(b[i][j][k] == 0) mx = -1;

  return mx;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> m >> n >> h; // indexed with j, i and k

  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      fill(day[i][j], day[i][j] + h, -1); 

  int x;
  for(int k = 0; k < h; k++)
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++) {
        cin >> x;
        b[i][j][k] = x;
        if(x == 1) {
          q.push({i, j, k});
          day[i][j][k] = 0;
        }
      }

  cout << bfs();
}