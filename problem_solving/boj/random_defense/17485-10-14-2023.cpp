#include <bits/stdc++.h>
using namespace std;

const int INF = 2e5;

int n, m;
int dp[1002][1002][3];
int b[1002][1002];
int dy[] = {-1, 0, 1};

bool oob(int y) {
  return y >= m || y < 0;
}

int solve(int x, int y, int dir) {
  if (x == n) return 0;
  int &ret = dp[x][y][dir];
  if (ret != -1) return ret;

  ret = INF;
  for (int d = 0; d < 3; d++) {
    if (d == dir) continue;
    int ny = y + dy[d];
    if (oob(ny)) continue;
    ret = min(ret, solve(x + 1, ny, d) + b[x][y]);
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
  int ans = INF;
  for (int j = 0; j < m; j++)
    ans = min(ans, solve(0, j, 3));
  cout << ans;
}
