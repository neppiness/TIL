#include <bits/stdc++.h>
using namespace std;

bool b[102][102];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 0; i < 4; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    for (int i = x1; i < x2; i++)
      fill(b[i] + y1, b[i] + y2, 1);
  }

  int ans = 0;
  for (int i = 0; i < 100; i++)
    for (int j = 0; j < 100; j++)
      ans += b[i][j];
  cout << ans;
}
