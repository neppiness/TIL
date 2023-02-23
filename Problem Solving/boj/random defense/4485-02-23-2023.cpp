#include <bits/stdc++.h>
using namespace std;

const int MX = 125 + 2;
const int INF = 0x7f7f7f7f;

int b[MX][MX];
int dist[MX][MX];

int n;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool oob(int x, int y) { return (x >= n || x < 0 || y >= n || y < 0); }

int solve() {
  queue<tuple<int, int, int>> q; // cx, cy, cost
  dist[0][0] = b[0][0];
  q.push({0, 0, b[0][0]});
  while(!q.empty()) {
    auto [cx, cy, co] = q.front(); q.pop();
    if(dist[cx][cy] != co) continue;
    for(int dir = 0; dir < 4; dir++) {
      int nx = cx + dx[dir];
      int ny = cy + dy[dir];
      int dco = co + b[nx][ny];
      if(oob(nx, ny)) continue;
      if(dco >= dist[nx][ny]) continue;
      dist[nx][ny] = dco;
      q.push({nx, ny, dco});
    }
  }
  return dist[n - 1][n - 1];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  int cnt = 1;
  while(n != 0) {
    memset(dist, 0x7f, sizeof(dist));
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
        cin >> b[i][j];
    int ans = solve();
    cout << "Problem " << cnt << ": " << ans << '\n';
    cnt++;
    cin >> n;
  }
}