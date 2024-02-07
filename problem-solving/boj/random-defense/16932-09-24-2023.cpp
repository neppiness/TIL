#include <bits/stdc++.h>
using namespace std;

int id = 0;
int n, m;
int b[1002][1002];
bool vis[1002][1002];
int ar[250'002]; // 최대 컴포넌트 개수, 500x500

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool oob(int x, int y) {
  return x >= n || x < 0 || y >= m || y < 0;
}

int bfs(int x, int y) {
  id++;
  int a = 1;

  queue<pair<int, int>> q;
  q.push({x, y});
  b[x][y] = id;
  while (!q.empty()) {
    auto [cx, cy] = q.front(); q.pop();
    for (int dir = 0; dir < 4; dir++) {
      int nx = cx + dx[dir];
      int ny = cy + dy[dir];
      if (oob(nx, ny)) continue;
      if (vis[nx][ny] || !b[nx][ny]) continue;
      vis[nx][ny] = 1;
      b[nx][ny] = id;
      a++;
      q.push({nx, ny});
    }
  }
  return ar[id] = a;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> b[i][j];

  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (vis[i][j] || !b[i][j]) continue;
      vis[i][j] = 1;
      ans = max(ans, bfs(i, j));
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (b[i][j]) continue;
      int tot = 1;
      vector<int> used_id;
      for (int dir = 0; dir < 4; dir++) {
        int ni = i + dx[dir];
        int nj = j + dy[dir];
        if (oob(ni, nj) || !b[ni][nj]) continue; 
        int nid = b[ni][nj];
        auto it = find(used_id.begin(), used_id.end(), nid);
        if (it != used_id.end()) continue;
        tot += ar[nid];
        used_id.push_back(nid);
      }
      ans = max(tot, ans);
    }
  }
  cout << ans;
}
