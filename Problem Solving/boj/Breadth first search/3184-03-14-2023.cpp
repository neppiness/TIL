#include <bits/stdc++.h>
using namespace std;

const int MX = 250;

int n, m, sh, wf;
char b[MX + 2][MX + 2];
bool vis[MX + 2][MX + 2];
queue<pair<int, int>> q;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool oob(int x, int y) { return (x >= n || x < 0 || y >= m || y < 0); } 

void solve(int x, int y) {
  int shtmp = 0, wftmp = 0;
  if(b[x][y] == 'v') wftmp++;
  else if(b[x][y] == 'o') shtmp++;

  vis[x][y] = 1; q.push({x, y});
  while(!q.empty()) {
    auto [cx, cy] = q.front(); q.pop();
    for(int dir = 0; dir < 4; dir++) {
      int nx = cx + dx[dir];
      int ny = cy + dy[dir];
      if(oob(nx, ny)) continue;
      if(vis[nx][ny] || b[nx][ny] == '#') continue;
      vis[nx][ny] = 1;
      q.push({nx, ny});
      if(b[nx][ny] == 'v') wftmp++;
      else if(b[nx][ny] == 'o') shtmp++;
    }
  }
  if(shtmp > wftmp) sh += shtmp;
  else wf += wftmp;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for(int i = 0; i < n; i++)
    cin >> b[i];
  
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++) {
      if(b[i][j] == '#' || vis[i][j]) continue;
      solve(i, j);
    }
  cout << sh << ' ' << wf;
}