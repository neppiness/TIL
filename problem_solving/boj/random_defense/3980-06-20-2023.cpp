#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
ll cache[35][35][3];
bool b[35][35];

int dx[] = {1, 1, 0};
int dy[] = {0, 1, 1};

bool OOB(int x, int y) {
  return (x >= n || x < 0 || y >= n || y < 0);
}

// dir = 0:세로, 1:대각선, 2:가로
ll solve(int cx, int cy, int dir) {
  if (cx == n - 1 && cy == n - 1) return 1;

  ll &ret = cache[cx][cy][dir];
  if (ret != -1) return ret;

  ret = 0;
  for (int nd : {dir - 1, dir, dir + 1}) {
    if (nd < 0 || nd >= 3) continue;
    if (nd == 1) { // 대각선
      bool is_valid = 1;
      for (int dir = 0; dir < 3; dir++) {
        int nx = cx + dx[dir];
        int ny = cy + dy[dir];
        if (OOB(nx, ny) || b[nx][ny]) is_valid = 0;
      }
      if (!is_valid) continue;
      ret += solve(cx + 1, cy + 1, nd);
    } else {
      int nx = cx + dx[nd];
      int ny = cy + dy[nd];
      if (OOB(nx, ny) || b[nx][ny]) continue;
      ret += solve(nx, ny, nd);
    }
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(cache, -1, sizeof(cache));

  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> b[i][j];

  cout << solve(0, 1, 2);
}