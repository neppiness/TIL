#include <bits/stdc++.h>
using namespace std;

const int MX = 100 + 2;

int n, m, t, cnt;

int b[MX][MX];
bool vis[MX][MX];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool oob(int x, int y) { return (x >= n || x < 0 || y >= m || y < 0); }

void chk_air() {
  queue<pair<int, int>> q;
  q.push({0, 0});
  vis[0][0] = 1;

  while(!q.empty()) {
    auto [cx, cy] = q.front(); q.pop();
    for(int dir = 0; dir < 4; dir++) {
      int nx = cx + dx[dir];
      int ny = cy + dy[dir];
      if(oob(nx, ny)) continue;
      if(vis[nx][ny]) continue;
      if(b[nx][ny] == 1) continue;
      vis[nx][ny] = 1;
      b[nx][ny] = 3;
      q.push({nx, ny});
    }
  }
}

void chk_chz(int x, int y) {
  queue<pair<int, int>> q;
  q.push({x, y});
  vis[x][y] = 1;

  while(!q.empty()) {
    auto [cx, cy] = q.front(); q.pop();
    bool gonna_melt = 0;
    for(int dir = 0; dir < 4; dir++) {
      int nx = cx + dx[dir];
      int ny = cy + dy[dir];
      if(b[nx][ny] == 3) {
        gonna_melt = 1;
        continue;
      }
      if(vis[nx][ny]) continue;
      vis[nx][ny] = 1;
      q.push({nx, ny});
    }
    if(gonna_melt) b[cx][cy] = 2;
  }
}

bool marking() {
  memset(vis, 0, sizeof(vis));

  chk_air();

  bool is_valid = 0;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      if(b[i][j] == 1 && !vis[i][j]) {
        chk_chz(i, j);
        is_valid = 1;
      }
  return is_valid;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      cin >> b[i][j];
  
  while(marking()) {
    t++; cnt = 0;
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++) {
        if(b[i][j] != 2) continue;
        b[i][j] = 0;
        cnt++;
      }
  }
  cout << t << '\n' << cnt;
}