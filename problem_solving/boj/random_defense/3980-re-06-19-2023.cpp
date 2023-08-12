#include <bits/stdc++.h>
using namespace std;

const int kInf = 0x3f3f3f3f;
int ab[11][11];

int solve(int cur, int status) {
  if (cur == 11) return 0;
  int ret = -kInf;
  for (int j = 0; j < 11; j++) {
    if (!ab[cur][j]) continue;
    int p = (1 << j);
    if (status & p) continue;
    ret = max(ret, ab[cur][j] + solve(cur + 1, status | p));
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    for (int i = 0; i < 11; i++)
      for (int j = 0; j < 11; j++)
        cin >> ab[i][j];
    cout << solve(0, 0) << '\n';
  }
}