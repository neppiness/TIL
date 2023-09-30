#include <bits/stdc++.h>
using namespace std;

const int INF = 3125;

int n; 
char b[7][7];
int mn = INF;
int mx = -INF;

int dx[] = {1, 0};
int dy[] = {0, 1};

bool oob(int x, int y) {
  return x >= n || x < 0 || y >= n || y < 0;
}

void solve(int cur, int x, int y) {
  if (x == n - 1 && y == n - 1) {
    mn = min(mn, cur);
    mx = max(mx, cur);
    return;
  }

  for (int dir = 0; dir < 2; dir++) {
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if (oob(nx, ny)) continue;
    for (int ddir = 0; ddir < 2; ddir++) {
      int nnx = nx + dx[ddir];
      int nny = ny + dy[ddir];
      if (oob(nnx, nny)) continue;
      int no = b[nnx][nny] - '0';
      int nxt;
      if (b[nx][ny] == '+') nxt = cur + no;
      else if (b[nx][ny] == '-') nxt = cur - no;
      else nxt = cur * no;
      solve(nxt, nnx, nny);
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> b[i][j];

  solve(b[0][0] - '0', 0, 0);
  cout << mx << ' ' << mn;
}
