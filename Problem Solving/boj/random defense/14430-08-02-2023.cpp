#include <bits/stdc++.h>
using namespace std;

int n, m;
bool b[302][302];
int dp[302][302];

bool oob(int x, int y) { return x >= n || x < 0 || y >= m || y < 0; }

int solve(int x, int y) {
  if (oob(x, y)) return 0;
  int &ret = dp[x][y];
  if (ret != -1) return ret;

  ret = b[x][y] + max(solve(x - 1, y), solve(x, y - 1));
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(dp, -1, sizeof(dp));

  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> b[i][j];

  cout << solve(n - 1, m - 1);
}