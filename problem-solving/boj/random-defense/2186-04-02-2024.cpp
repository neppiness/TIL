#include <bits/stdc++.h>
using namespace std;

int n, m, k;
string s; 
char b[102][102];
int dp[102][102][82];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool oob(int x, int y) {
  return x < 0 || x >= n || y < 0 || y >= m;
}

int solve(int cx, int cy, int idx) {
  if (idx == s.length() - 1) return 1;
  int &ret = dp[cx][cy][idx];
  if (ret!= -1) return ret;

  ret = 0;
  for (int dir = 0; dir < 4; dir++) {
    for (int dist = 1; dist <= k; dist++) {
      int nx = cx + dist * dx[dir];
      int ny = cy + dist * dy[dir];
      if (oob(nx, ny) || b[nx][ny] != s[idx + 1]) continue;
      ret += solve(nx, ny, idx + 1);
    }
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  memset(dp, -1, sizeof(dp));

  cin >> n >> m >> k;
  for (int i = 0; i < n; i++)
    cin >> b[i];
  cin >> s;
  
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (b[i][j] != s[0]) continue;
      ans += solve(i, j, 0);
    }
  }
  cout << ans;
}
