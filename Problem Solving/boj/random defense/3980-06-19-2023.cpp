#include <bits/stdc++.h>
using namespace std;

int ans;
int ab[11][11];

void solve(int cur, int status, int tot) {
  if (cur == 11) { ans = max(ans, tot); return; }

  for (int j = 0; j < 11; j++) {
    if (!ab[cur][j]) continue;
    int p = (1 << j);
    if (status & p) continue;
    solve(cur + 1, status | p, tot + ab[cur][j]);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    ans = 0;
    for (int i = 0; i < 11; i++)
      for (int j = 0; j < 11; j++)
        cin >> ab[i][j];
    solve(0, 0, 0);
    cout << ans << '\n';
  }
}