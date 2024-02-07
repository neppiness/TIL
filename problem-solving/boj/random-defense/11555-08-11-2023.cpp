#include <bits/stdc++.h>
using namespace std;

int n, k;
bool b[2][100'002];
int dist[2][100'002];

bool oob(int y) {
  return y >= n;
}

bool solve() {
  queue<pair<int, int>> q;
  q.push({0, 0});
  dist[0][0] = 0;
  while (!q.empty()) {
    auto [cx, cy] = q.front(); q.pop();
    for (int ny : {cy - 1, cy + 1}) {
      if (oob(ny)) return 1;
      if (dist[cx][ny] != -1) continue;
      if (!b[cx][ny]) continue;
      if (ny < dist[cx][cy] + 1) continue;
      dist[cx][ny] = dist[cx][cy] + 1;
      q.push({cx, ny});
    }
    int nx = (cx + 1) % 2;
    int ny = cy + k;
    if (oob(ny)) return 1;
    if (dist[nx][ny] != -1) continue;
    if (!b[nx][ny]) continue;
    if (ny < dist[cx][cy] + 1) continue;
    dist[nx][ny] = dist[cx][cy] + 1;
    q.push({nx, ny});
  }
  return 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(dist, -1, sizeof(dist));
  cin >> n >> k;
  for (int i = 0; i < 2; i++) {
    string board; cin >> board;
    for (int j = 0; j < n; j++)
      b[i][j] = (board[j] == '1');
  }
  cout << solve();
}