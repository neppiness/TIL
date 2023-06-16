#include <bits/stdc++.h>
using namespace std;

int n, m, ans;
char b[502][502];
int cache[502][502];

bool OOB(int x, int y) {
  return (x >= n || x < 0 || y >= m || y < 0);
}

int solve(int x, int y) {
  if (OOB(x, y)) return 1;
  int &ret = cache[x][y];
  if (ret != -1) return ret;

  ret = 0;
  switch(b[x][y]) {
    case 'U': ret = solve(x - 1, y); break;
    case 'R': ret = solve(x, y + 1); break;
    case 'D': ret = solve(x + 1, y); break;
    default : ret = solve(x, y - 1); break;
  }
  if (ret == 1) ans++;
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(cache, -1, sizeof(cache));

  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> b[i];

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      solve(i, j);
  cout << ans;
}