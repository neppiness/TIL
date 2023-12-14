#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll pas[32][32];

ll solve(int n, int r) {
  n--; r--;
  if (r == n || r == 0) {
    return pas[n][r] = 1;
  }
  ll &ret = pas[n][r];
  if (ret != -1) return ret;
  return ret = solve(n, r) + solve(n, r + 1);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(pas, -1, sizeof(pas));

  int r, c, w;
  cin >> r >> c >> w;
  ll tot = 0;
  for (int i = r; i < r + w; i++)
    for (int j = c; j <= c + i - r; j++)
      tot += solve(i, j);
  cout << tot;
}
