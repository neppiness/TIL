#include <bits/stdc++.h>
using namespace std;

int b[101][101];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  while (n--) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    for (int i = x1; i <= x2; i++)
      for (int j = y1; j <= y2; j++)
        b[i][j]++;
  }

  int ans = 0;
  for (int i = 1; i <= 100; i++)
    for (int j = 1; j <= 100; j++)
      ans += (b[i][j] > m);
  cout << ans;
}
