#include <bits/stdc++.h>
using namespace std;

int m, n, k; // m: x-dir., n: y-dir.
int b[102][102];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

vector<int> ans;
queue<pair<int, int>> q;

void solve(int x, int y) {
  int ar = 1;
  b[x][y] = 1;
  q.push({x, y});
  
  int cx, cy, nx, ny;
  while(!q.empty()) {
    tie(cx, cy) = q.front(); q.pop();
    for(int d = 0; d < 4; d++) {
      nx = cx + dx[d];
      ny = cy + dy[d];
      if(nx >= m || nx < 0) continue;
      if(ny >= n || ny < 0) continue;
      if(b[nx][ny]) continue;
      ar++;
      b[nx][ny] = 1;
      q.push({nx, ny});
    }
  }
  ans.push_back({ar});
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> m >> n >> k;

  int x1, y1, x2, y2;
  while(k--) {
    cin >> x1 >> y1 >> x2 >> y2;
    for(int x = x1; x < x2; x++)
      for(int y = y1; y < y2; y++)
        b[y][x] = -1;
  }
  for(int i = 0; i < m; i++)
    for(int j = 0; j < n; j++)
      if(!b[i][j]) solve(i, j);
  
  sort(ans.begin(), ans.end());
  cout << ans.size() << '\n';
  for(int ar : ans)
    cout << ar << ' ';
}