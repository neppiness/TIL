#include <bits/stdc++.h>
using namespace std;

int n, m;

char b[602][602];
bool vis[602][602];
queue<pair<int, int>> q;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool OOB(int x, int y) {
  return (x >= n || x < 0 || y >= m || y < 0);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char c; cin >> c;
      b[i][j] = c;
      if (c == 'I') {
        q.push({i, j});
        vis[i][j] = 1;
      }
    }
  }

  int ans = 0;
  while (!q.empty()) {
    auto [cx, cy] = q.front(); q.pop();
    for (int dir = 0; dir < 4; dir++) {
      int nx = cx + dx[dir];
      int ny = cy + dy[dir];
      if (OOB(nx, ny)) continue;
      if (vis[nx][ny] || b[nx][ny] == 'X') continue;
      if (b[nx][ny] == 'P') ans++;
      vis[nx][ny] = 1;
      q.push({nx, ny});
    }
  }
  if (ans) cout << ans;
  else cout << "TT";
}