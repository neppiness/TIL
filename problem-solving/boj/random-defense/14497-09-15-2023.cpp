#include <bits/stdc++.h>
using namespace std;

int n, m;
queue<pair<int, int>> q;
pair<int, int> st;
char b[302][302];
bool vis[302][302];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool oob(int x, int y) {
  return x >= n || x < 0 || y >= m || y < 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  
  int x, y;
  cin >> x >> y;
  st = {--x, --y};
  cin >> x >> y;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> b[i][j];

  int cnt = 0;
  while (++cnt) {
    memset(vis, 0, sizeof(vis));
    q.push(st);
    vis[st.first][st.second] = 1;
    while (!q.empty()) {
      auto [cx, cy] = q.front(); q.pop();
      for (int dir = 0; dir < 4; dir++) {
        int nx = cx + dx[dir];
        int ny = cy + dy[dir];
        if (oob(nx, ny) || vis[nx][ny]) continue;
        vis[nx][ny] = 1;
        if (b[nx][ny] == '1') {
          b[nx][ny] = '0';
          continue;
        }
        if (b[nx][ny] == '#') {
          cout << cnt;
          return 0;
        }
        q.push({nx, ny});
      }
    }
  }
}
