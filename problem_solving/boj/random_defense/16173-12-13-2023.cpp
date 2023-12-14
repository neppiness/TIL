#include <bits/stdc++.h>
using namespace std;

int n;
int b[4][4], dp[4][4];

bool solve(int x, int y) {
  if (x >= n || y >= n) return 0;
  if (x == n - 1 && y == n - 1) return 1;

  int &ret = dp[x][y];
  if (ret != -1) return ret;
  if (b[x][y] == 0) return ret = 0;

  ret = solve(x + b[x][y], y);
  return ret |= solve(x, y + b[x][y]);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(dp, -1, sizeof(dp));

  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> b[i][j];
  
  if (solve(0, 0)) cout << "HaruHaru";
  else cout << "Hing";
}
