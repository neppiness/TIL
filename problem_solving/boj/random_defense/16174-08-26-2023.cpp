#include <bits/stdc++.h>
using namespace std;

const string OUT[] = { "Hing", "HaruHaru" };

int n;
int b[66][66];
int dp[66][66];

bool solve(int x, int y) {
  if (x >= n || x < 0 || y >= n || y < 0) return 0;
  if (b[x][y] == -1) return 1;
  if (b[x][y] == 0) return 0;

  int &ret = dp[x][y];
  if (ret != -1) return ret;
  
  ret = solve(x, y + b[x][y]);
  ret |= solve(x + b[x][y], y);
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(dp, -1, sizeof(dp));

  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> b[i][j];
  
  cout << OUT[solve(0, 0)];
}
