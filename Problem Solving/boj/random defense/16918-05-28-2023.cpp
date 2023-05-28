#include <bits/stdc++.h>
using namespace std;

int n, m, t;
int b[202][202];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool oob(int x, int y) {
  return (x >= n || x < 0 || y >= m || y < 0);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> t;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      char c; cin >> c;
      if (c == 'O') b[i][j] = 1;
    }

  int cnt = 0;
  while (t-- > 0) {
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        if (b[i][j] != 0) b[i][j]++;
        else if (cnt == 1) b[i][j] ++;
      }

    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        if (b[i][j] != 4) continue;
        q.push({i, j});
        b[i][j] = 0;
      }
    while (!q.empty()) {
      auto [cx, cy] = q.front(); q.pop();
      for (int dir = 0; dir < 4; dir++) {
        int nx = cx + dx[dir];
        int ny = cy + dy[dir];
        if (oob(nx, ny)) continue;
        b[nx][ny] = 0;
      }
    }
    if (++cnt == 2) cnt -= 2;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (b[i][j] == 0) cout << '.';
      else cout << 'O';
    }
    cout << '\n';
  }
}