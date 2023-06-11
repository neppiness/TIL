#include <bits/stdc++.h>
using namespace std;

int a[3], tmp[3];
int cache[502][502][502];

bool solve(int x, int y, int z);

bool setandret(int x, int y, int z) {
  tmp[0] = x; tmp[1] = y; tmp[2] = z;
  sort(tmp, tmp + 3);
  return solve(tmp[0], tmp[1], tmp[2]);
}

bool solve(int x, int y, int z) {
  int &ret = cache[x][y][z];
  if (ret != -1) return ret;
  if (x == y && y == z) return ret = 1;

  ret = setandret(x + x, y, z - x);
  if (x != y)
    ret |= setandret(x + x, y - x, z);
  if (y != z)
    ret |= setandret(x, y + y, z - y);
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(cache, -1, sizeof(cache));

  for (int i = 0; i < 3; i++)
    cin >> a[i];
  sort(a, a + 3);

  cout << solve(a[0], a[1], a[2]);
}