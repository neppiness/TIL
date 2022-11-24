#include <bits/stdc++.h>
using namespace std;

int b[1027][1027];
int ps[1027][1027];

int solve() {
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  x1--; y1--;
  return ps[x2][y2] - ps[x2][y1] - ps[x1][y2] + ps[x1][y1];
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n, m;
  cin >> n >> m;

  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
      cin >> b[i][j];

  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++) {
      ps[i][j] += b[i][j] + ps[i-1][j];
    }

  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++) {
      ps[i][j] += ps[i][j-1];
    }

  for(int i = 0; i < m; i++)
    cout << solve() << '\n';
}