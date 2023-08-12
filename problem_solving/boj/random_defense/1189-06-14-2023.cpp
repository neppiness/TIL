#include <bits/stdc++.h>
using namespace std;

int n, m, k, ans;
char b[7][7];
bool vis[7][7];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool OOB(int x, int y) {
  return (x >= n || x < 0 || y >= m || y < 0);
}

void Solve(int x, int y, int r) {
  if (r == 0) {
    ans += (x == 0 && y == m - 1);
    return;
  }
  vis[x][y] = 1;
  for (int dir = 0; dir < 4; dir++) {
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if (OOB(nx, ny) || vis[nx][ny]) continue;
    if(b[nx][ny] == 'T') continue;
    Solve(nx, ny, r - 1);
  }
  vis[x][y] = 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> k;
  for (int i = 0; i < n; i++)
    cin >> b[i];
    
  Solve(n - 1, 0, k - 1);
  cout << ans;
}