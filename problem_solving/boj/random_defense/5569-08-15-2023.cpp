#include <bits/stdc++.h>
using namespace std;

const int MOD = 100'000;

int dp[102][102][2][2]; // dp[x][y][dir][is_after_turned];

int n, m;
int dx[] = {1, 0};
int dy[] = {0, 1};

int solve(int x, int y, int dir, bool is_after_turned) {
  if (x == n - 1 && y == m - 1) return 1;
  if (x >= n || y >= m) return 0;
  int &ret = dp[x][y][dir][is_after_turned];
  if (ret != -1) return ret;

  ret = solve(x + dx[dir], y + dy[dir], dir, 0); 
  if (!is_after_turned) {
    int ndir = (dir + 1) % 2;
    ret += solve(x + dx[ndir], y + dy[ndir], ndir, 1);
    if (ret >= MOD) ret -= MOD;
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(dp, -1, sizeof(dp));

  cin >> n >> m;
  int ans = solve(1, 0, 0, 0) + solve(0, 1, 1, 0);
  if (ans >= MOD) ans -= MOD;
  cout << ans;
}
