#include <bits/stdc++.h>
using namespace std;

const int MX = 100;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int n, m, k, ans, cnt;
bool b[MX + 2][MX + 2];
bool vis[MX + 2][MX + 2];

bool oob(int x, int y) { return (x >= n || x < 0 || y >= m || y < 0); }

void dfs(int cx, int cy) {
  for(int dir = 0; dir < 4; dir++) {
    int nx = cx + dx[dir];
    int ny = cy + dy[dir];
    if(oob(nx, ny)) continue;
    if(!b[nx][ny] || vis[nx][ny]) continue;
    vis[nx][ny] = 1;
    cnt++;
    ans = max(cnt, ans);
    dfs(nx, ny);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> k;

  while(k--) {
    int x, y; cin >> x >> y;
    b[x - 1][y - 1] = 1;
  }

  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      if(b[i][j] && !vis[i][j]) {
        vis[i][j] = 1;
        cnt = 1;
        dfs(i, j); 
      }
  cout << ans;
}