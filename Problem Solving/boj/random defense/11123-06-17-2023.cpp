#include <bits/stdc++.h>
using namespace std;

int n, m;
char b[102][102];
bool vis[102][102];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

queue<pair<int, int>> q;

bool OOB(int x, int y) {
  return (x >= n || x < 0 || y >= m || y < 0);
}

void BFS(int x, int y) {
  vis[x][y] = 1;
  q.push({x, y});
  while (!q.empty()) {
    auto [cx, cy] = q.front(); q.pop();
    for (int dir = 0; dir < 4; dir++) {
      int nx = cx + dx[dir];
      int ny = cy + dy[dir];
      if (OOB(nx, ny)) continue;
      if (b[nx][ny] == '.' || vis[nx][ny]) continue;
      vis[nx][ny] = 1;
      q.push({nx, ny});
    }
  }
}

void Solve() {
  int cnt = 0;
  memset(vis, 0, sizeof(vis));
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> b[i];
  
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if (b[i][j] == '.' || vis[i][j]) continue;
      BFS(i, j); cnt++;
    }
  cout << cnt << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) Solve();
}