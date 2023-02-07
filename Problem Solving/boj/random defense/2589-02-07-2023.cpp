#include <bits/stdc++.h>
using namespace std;

const int MX = 50;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int n, m;
char b[MX + 2][MX + 2];
int dist[MX + 2][MX + 2]; // 거리

vector<pair<int, int>> cand;
int ans;

bool oob(int x, int y) { return (x >= n || x < 0 || y >= m || y < 0); }

void solve(int x, int y, bool code) {
  dist[x][y] = 0;
  queue<pair<int, int>> q;
  q.push({x, y});

  int mx = 0;
  while(!q.empty()) {
    auto [cx, cy] = q.front(); q.pop();
    int adj = 0;
    for(int dir = 0; dir < 4; dir++) {
      int nx = cx + dx[dir];
      int ny = cy + dy[dir];
      if(oob(nx, ny)) continue;
      if(b[nx][ny] == 'W') continue;
      if(dist[nx][ny] != -1) continue;
      dist[nx][ny] = dist[cx][cy] + 1;
      q.push({nx, ny});
      ans = max(dist[nx][ny], ans);
      adj++;
    }
    if(code && adj < 2) cand.push_back({cx, cy});
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(dist, -1, sizeof(dist));

  cin >> n >> m;
  for(int i = 0; i < n; i++)
    cin >> b[i];

  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      if(dist[i][j] == -1 && b[i][j] == 'L') 
        solve(i, j, 1);
  
  for(auto [x, y] : cand) {
    memset(dist, -1, sizeof(dist));
    solve(x, y, 0);
  }
  cout << ans;
}