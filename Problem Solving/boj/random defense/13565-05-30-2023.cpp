#include <bits/stdc++.h>
using namespace std;

int n, m;
queue<pair<int, int>> q;
bool b[1003][1003];
bool vis[1003][1003];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool OOB(int x, int y) {
  return (x < 0 || x > n + 1 || y < 0 || y >= m);
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < m; j++) {
      char c; cin >> c;
      if (c == '1') b[i][j] = 1;
    }
  }

  for (int j = 0; j < m; j++) {
    q.push({0, j}); vis[0][j] = 1;
  }

  while (!q.empty()) {
    auto [cx, cy] = q.front(); q.pop();
    for (int dir = 0; dir < 4; dir++) {
      int nx = cx + dx[dir];
      int ny = cy + dy[dir];
      if (OOB(nx, ny)) continue;
      if (vis[nx][ny] || b[nx][ny]) continue;
      vis[nx][ny] = 1;
      q.push({nx, ny});
    }
  }

  if (vis[n + 1][0]) cout << "YES";
  else cout << "NO";
}