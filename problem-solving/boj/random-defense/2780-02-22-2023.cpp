#include <bits/stdc++.h>
using namespace std;

const int M = 1'234'567;
const int MX = 1000 + 2;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int cache[MX][4][3];

bool oob(int x, int y) { return (x >= 3 || x < 0 || y >= 3 || y < 0); }

int calc(int len, int cx, int cy) {
  int &ret = cache[len][cx][cy];
  if(ret != -1) return ret;
  if(len == 1) return ret = 1;

  ret = 0;
  for(int dir = 0; dir < 4; dir++) {
    int nx = cx + dx[dir];
    int ny = cy + dy[dir];
    if(!(nx == 3 && ny == 0) && oob(nx, ny)) continue;
    ret += calc(len - 1, nx, ny);
    if(ret >= M) ret -= M;
  }
  return ret;
}

int solve(int len) {
  int ans = 0;
  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++) {
      ans += calc(len, i, j);
      if(ans >= M) ans -= M;
    }
  ans += calc(len, 3, 0);
  if(ans >= M) ans -= M;
  return ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(cache, -1, sizeof(cache));

  int t; cin >> t;
  while(t--) {
    int len; cin >> len;
    cout << solve(len) << '\n';
  }
}