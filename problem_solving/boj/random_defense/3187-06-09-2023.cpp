#include <bits/stdc++.h>
using namespace std;

int n, m;
bool vis[252][252];
char b[252][252];
int cntv, cntk;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
queue<pair<int, int>> q;

bool OOB(int x, int y) {
  return (x >= n || x < 0 || y >= m || y < 0);
}

void Solve(int x, int y) {
  int k = (b[x][y] == 'k'), v = (b[x][y] == 'v');
  vis[x][y] = 1;
  q.push({x, y});
  while (!q.empty()) {
    auto [cx, cy] = q.front(); q.pop();
    for (int dir = 0; dir < 4; dir++) {
      int nx = cx + dx[dir];
      int ny = cy + dy[dir];
      if (OOB(nx, ny) || b[nx][ny] == '#') continue;
      if (vis[nx][ny]) continue;
      if (b[nx][ny] == 'v') v++;
      if (b[nx][ny] == 'k') k++;
      vis[nx][ny] = 1;
      q.push({nx, ny});
    }
  }
  if (k > v) cntk += k;
  else cntv += v;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> b[i];
  
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (!vis[i][j] && b[i][j] != '#') Solve(i, j);

  cout << cntk << ' ' << cntv;
}