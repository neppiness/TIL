#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MX = 500 + 2;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

ll ans; int n;
ll cache[MX][MX];
int b[MX][MX];

bool oob(int x, int y) { return (x >= n || x < 0 || y >= n || y < 0); }

ll solve(int x, int y) {
  ll &ret = cache[x][y];
  if(ret != -1) return ret;
  ret = 0;
  for(int dir = 0; dir < 4; dir++) {
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if(oob(nx, ny)) continue;
    if(b[x][y] >= b[nx][ny]) continue;
    ret = max(ret, solve(nx, ny));
  }
  ret++;
  ans = max(ret, ans);
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(cache, -1, sizeof(cache));

  cin >> n;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      cin >> b[i][j];
  
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      solve(i, j);

  cout << ans;
}