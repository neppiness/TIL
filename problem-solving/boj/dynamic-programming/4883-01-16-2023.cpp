#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MX = 100'000;
const int dx[] = {-1, -1, -1, 0};
const int dy[] = {-1, 0, 1, -1};

int n, no = 1;
int cache[MX + 2][3];
int b[MX + 2][3];

bool oob(int x, int y) { return (x >= n || x < 0 || y >= 3 || y < 0); }

int ans(int cx, int cy) {
  int &c = cache[cx][cy];
  if(c != INF) return c;
  for(int dir = 0; dir < 4; dir++) {
    int px = cx + dx[dir];
    int py = cy + dy[dir];
    if(oob(px, py)) continue;
    c = min(c, ans(px, py));
  }
  return c = c + b[cx][cy];
}

void solve() {
  for(int i = 0; i < n; i++)
    fill(cache[i], cache[i] + 3, INF);

  for(int i = 0; i < n; i++)
    for(int j = 0; j < 3; j++)
      cin >> b[i][j];

  cache[0][1] = b[0][1];

  cout << no << ". " << ans(n - 1, 1) << '\n';
  no++;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  while(n) {
    solve();
    cin >> n;
  }
}