#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MX = 100;

int dx[] = {1, 0}, dy[] = {0, 1};
int b[MX + 2][MX + 2];
ll cache[MX + 2][MX + 2];
int n;

bool oob(int x, int y) { return (x < 0 || x >= n || y < 0 || y >= n); }

ll solve(int cx, int cy) {
  ll &ret = cache[cx][cy];
  if(ret != -1) return ret;
  if(cx == n - 1 && cy == n - 1) return 1; // base case

  ret = 0;
  for(int dir = 0; dir < 2; dir++) {
    int nx = cx + b[cx][cy] * dx[dir];
    int ny = cy + b[cx][cy] * dy[dir];
    if(oob(nx, ny)) continue;
    ret += solve(nx, ny);
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  memset(cache, -1, sizeof(cache));

  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      cin >> b[i][j];
  
  cout << solve(0, 0);
}