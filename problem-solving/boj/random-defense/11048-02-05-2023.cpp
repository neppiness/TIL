#include <bits/stdc++.h>
using namespace std;

const int MX = 1'000;
const int DX[] = {-1, 0, -1};
const int DY[] = {0, -1, -1};

int c[MX + 2][MX + 2];
int s[MX + 2][MX + 2];

int n, m;

bool oob(int x, int y) { return (x >= n || x < 0 || y >= m || y < 0); }

int solve(int cx, int cy) {
  int &ret = s[cx][cy];
  if(ret != -1) return ret;
  ret = c[cx][cy];
  int mx = 0;
  for(int dir = 0; dir < 3; dir++) {
    int nx = cx + DX[dir];
    int ny = cy + DY[dir];
    if(oob(nx, ny)) continue;
    mx = max(mx, solve(nx, ny));
  }
  return ret += mx;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(s, -1, sizeof(s));
  
  cin >> n >> m;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      cin >> c[i][j];
  
  cout << solve(n - 1, m - 1);
}