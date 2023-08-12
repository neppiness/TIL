#include <bits/stdc++.h>
using namespace std;

int a[3], tot;
int cache[1502][1502];

bool solve(int x, int y) {
  int &ret = cache[x][y];
  if (ret != -1) return ret;

  int z = tot - x - y;
  if (x == y && y == z) return ret = 1;

  int tmp[3] = {x, y, z};
  sort(tmp, tmp + 3);

  ret = 0;
  
  for (int i = 0; i < 3; i++) {
    for (int j = i + 1; j < 3; j++) {
      if (tmp[i] == tmp[j]) continue;
      if (solve(tmp[i] + tmp[i], tmp[j] - tmp[i]))
        return ret = 1;
    }
  }
  return ret = 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(cache, -1, sizeof(cache));

  for (int i = 0; i < 3; i++) {
    cin >> a[i]; tot += a[i];
  }

  sort(a, a + 3);
  bool ans = solve(a[0], a[1]);
  ans |= solve(a[0], a[2]);
  ans |= solve(a[1], a[2]);
  cout << ans;
}