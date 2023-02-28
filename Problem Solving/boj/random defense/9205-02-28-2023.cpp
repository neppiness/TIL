#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MX = 100 + 2;

int n;
int d[MX][MX];

struct coord {
  int x, y;
  coord(int x_ = 0, int y_ = 0): x(x_), y(y_) {}

  int dist(coord &r) { return abs(x - r.x) + abs(y - r.y); }
} c[MX];

void solve() {
  memset(d, 0x3f, sizeof(d));

  cin >> n; n += 2;
  for(int i = 0; i < n; i++) {
    int x1, y1; cin >> x1 >> y1;
    c[i].x = x1; c[i].y = y1;
  }

  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++) {
      int dist = c[i].dist(c[j]);
      if(dist > 1000) continue;
      d[i][j] = dist;
      d[j][i] = dist;
    }

  for(int k = 0; k < n; k++)
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        
  if(d[0][n - 1] == INF) cout << "sad" << '\n';
  else cout << "happy" << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--) solve();
}