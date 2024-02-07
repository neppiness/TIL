#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;

int dx[] = {1, 0};
int dy[] = {0, 1};

ll dp[102][102];
bool is_in_cons[102][102][2]; // is_in_cons[w][h][dir]

ll solve(int x, int y) {
  if (x > n || y > m) return 0;
  if (x == n && y == m) return 1;

  ll &ret = dp[x][y];
  if (ret != -1) return ret;
  
  ret = 0;
  for (int dir : {0, 1}) {
    if (is_in_cons[x][y][dir]) continue;
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    ret += solve(nx, ny);
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  int k; cin >> k;
  while (k--) {
    int u1, v1, u2, v2;
    cin >> u1 >> v1 >> u2 >> v2;
    if (pair<int, int>(u1, v1) > pair<int, int>(u2, v2)) {
      swap(u1, u2);
      swap(v1, v2);
    }
    if (u1 == u2) { // dir == 1
      is_in_cons[u1][v1][1] = 1;
    } else {
      is_in_cons[u1][v1][0] = 1;
    }
  }

  memset(dp, -1, sizeof(dp));
  cout << solve(0, 0);
}
