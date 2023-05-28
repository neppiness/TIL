#include <bits/stdc++.h>
using namespace std;

int n, m;
char b[52][52];
int dist[52][52][28];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool OOB(int x, int y) {
  return (x >= n || x < 0 || y >= m || y < 0);
}

bool Solve(int x, int y) {
  int col = b[x][y] - 'A';

  stack<pair<int, int>> st;
  st.push({x, y});
  dist[x][y][col] = 1;

  while (!st.empty()) {
    auto [cx, cy] = st.top(); st.pop();
    for (int dir = 0; dir < 4; dir++) {
      int nx = cx + dx[dir];
      int ny = cy + dy[dir];
      if (OOB(nx, ny)) continue;
      if (b[nx][ny] != b[x][y]) continue;
      if (dist[nx][ny][col] != -1) {
        if (abs(dist[cx][cy][col] - dist[nx][ny][col]) >= 3) return 1;
        continue;
      }
      dist[nx][ny][col] = dist[cx][cy][col] + 1;
      st .push({nx, ny});
    }
  }
  return 0;
}

bool IsFound() {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      int col = b[i][j] - 'A';
      if (dist[i][j][col] != -1) continue;
      if (Solve(i, j)) return 1;
    }
  return 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(dist, -1, sizeof(dist));

  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> b[i];

  if (IsFound()) cout << "Yes";
  else cout << "No";

  cout << '\n';
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cout << dist[i][j][0] << " \n"[j + 1 == m];
}