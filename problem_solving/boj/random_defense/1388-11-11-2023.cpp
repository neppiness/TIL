#include <bits/stdc++.h>
using namespace std;

int cnt;
int n, m;
char b[52][52];
bool v[52][52];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void solve(int x, int y) {
  cnt++;
  v[x][y] = 1;
  char c = b[x][y];
  int dir[2];
  if (c == '-') {
    dir[0] = 1;
    dir[1] = 3;
  } else {
    dir[0] = 0;
    dir[1] = 2;
  }

  queue<pair<int, int>> q;
  q.push({x, y});
  while (!q.empty()) {
    auto [cx, cy] = q.front(); q.pop();
    for (int d = 0; d < 2; d++) {
      int nx = cx + dx[dir[d]];
      int ny = cy + dy[dir[d]];
      if (b[nx][ny] != c) continue;
      if (v[nx][ny]) continue;
      v[nx][ny] = 1;
      q.push({nx, ny});
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> b[i];

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (!v[i][j]) solve(i, j);
  cout << cnt;
}
