#include <bits/stdc++.h>
using namespace std;

int n;
int cache[10'002][6];
int dice[10'002][6];

int GetOppo(int side) {
  switch(side) {
    case 0: return 5;
    case 1: return 3;
    case 2: return 4;
    case 3: return 1;
    case 4: return 2;
    default: return 0;
  }
}

int solve(int lv, int upper) {
  int &ret = cache[lv][upper];
  if (lv == 0) return ret = 0;
  if (ret != -1) return ret;

  ret = 0;
  int lower = GetOppo(upper);
  int lower_val = dice[lv][lower];

  for (int i = 0; i < 6; i++) {
    if (i == upper || i == lower) continue;
    ret = max(ret, dice[lv][i]);
  }

  for (int i = 0; i < 6; i++)
    if (dice[lv - 1][i] == lower_val) lower = i;

  return ret += solve(lv - 1, lower);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(cache, -1, sizeof(cache));

  cin >> n;
  for (int i = 1; i <= n; i++)
    for (int j = 0; j < 6; j++)
      cin >> dice[i][j];

  int ans = 0; 
  for (int j = 0; j < 6; j++)
    ans = max(ans, solve(n, j));
  cout << ans;
}