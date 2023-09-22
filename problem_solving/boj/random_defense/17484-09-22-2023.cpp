#include <bits/stdc++.h>
using namespace std;

int n, m;
int b[8][8]; // b[x][y]
int dp[8][8][5]; // dp[x][y][dir]
int dy[] = {-1, 0, 1};

int solve(int cx, int cy, int cdir) {
  if (cx == -1) return 0;

  int &ret = dp[cx][cy][cdir];
  if (ret != -1) return ret;

  ret = 10000;
  for (int pdir = 0; pdir < 3; pdir++) {
    if (pdir == cdir) continue;
    int px = cx - 1;
    int py = cy + dy[pdir];
    if (py >= m || py < 0) continue;
    ret = min(ret, solve(px, py, pdir) + b[cx][cy]);
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> b[i][j];
  
  memset(dp, -1, sizeof(dp));

  int ans = 10000;
  for (int j = 0; j < m; j++)
    for (int dir = 0; dir < 3; dir++)
      ans = min(ans, solve(n, j, dir));
  cout << ans;
}
