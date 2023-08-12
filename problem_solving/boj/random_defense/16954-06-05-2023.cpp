#include <bits/stdc++.h>
using namespace std;

const int n = 8;
const int dx[] = {0, 1, 0, -1, 0, 1, 1, -1, -1};
const int dy[] = {0, 0, 1, 0, -1, 1, -1, 1, -1};

char b[10][10];
bool vis[10][10];

queue<pair<int, int>> cur_q, nxt_q;

bool OOB(int x, int y) {
  return (x >= n || x < 0 || y >= n || y < 0);
}

bool solve() {
  nxt_q.push({0, 0});
  while (!nxt_q.empty()) {
    cur_q = nxt_q;
    nxt_q = queue<pair<int, int>>();
    memset(vis, 0, sizeof(vis));
    while (!cur_q.empty()) {
      auto [cx, cy] = cur_q.front(); cur_q.pop();
      if (b[cx][cy] == '#') continue;
      for (int dir = 0; dir < 9; dir++) {
        int nx = cx + dx[dir];
        int ny = cy + dy[dir];
        if (OOB(nx, ny) || vis[nx][ny]) continue;
        if (b[nx][ny] == '#') continue;
        if (nx == 7 && ny == 7) return 1;
        vis[nx][ny] = 1;
        nxt_q.push({nx, ny});
      }
    }
    for (int i = 0; i < n - 1; i++)
      for (int j = 0; j < n; j++)
        b[i][j] = b[i + 1][j];
    fill(b[n - 1], b[n - 1] + n, '.');
  }
  return 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = n - 1; i >= 0; i--)
    cin >> b[i];

  cout << solve();
}