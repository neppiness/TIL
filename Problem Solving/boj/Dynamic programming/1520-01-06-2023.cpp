#include <bits/stdc++.h>
using namespace std;

const int MX = 502;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int n, m;
int b[MX][MX], cache[MX][MX];

bool oob(int x, int y) {
  return (x >= m || x < 0 || y >= n || y < 0);
}

int solve(int cx, int cy) {
  if(cx == 0 && cy == 0) return 1;
  int &ret = cache[cx][cy];
  if(ret != -1) return ret;

  ret = 0;
  for(int dir = 0; dir < 4; dir++) {
    int nx = cx + dx[dir];
    int ny = cy + dy[dir];
    if(oob(nx, ny)) continue;
    if(b[nx][ny] <= b[cx][cy]) continue;
    ret += solve(nx, ny);
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(cache, -1, sizeof(cache));
  cin >> m >> n;
  for(int i = 0; i < m; i++)
    for(int j = 0; j < n; j++)
      cin >> b[i][j];
  
  cout << solve(m - 1, n - 1);
}
