#include <bits/stdc++.h>
using namespace std;

const int MX = 1000 + 5;

int n, m;

char b[MX][MX];
bool vis[MX][MX];

int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
int ans;

bool oob(int x, int y) { return (x >= n || x < 0 || y >= m || y < 0); }

void fillBg() {
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
      if(b[nx][ny] == '#') continue;
      vis[nx][ny] = 1;
      q.push({nx, ny});
    }
  }
}

int solution(vector<string> grid) {
  n = grid.size();
  m = grid[0].size();

  for(int i = 0; i < n + 2; i++)
    for(int j = 0; j < m + 2; j++)
      b[i][j] = '.';

  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      b[i + 1][j + 1] = grid[i][j];

  n += 2, m += 2;
  
  fillBg();

  for(int i = 1; i < n - 1; i++)
    for(int j = 1; j < m - 1; j++)
      if(!vis[i][j]) ans++;

  return ans;
}