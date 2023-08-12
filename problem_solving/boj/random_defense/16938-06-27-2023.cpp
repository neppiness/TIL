#include <bits/stdc++.h>
using namespace std;

int n, l, r, x, ans;
int d[17];

void solve(int to_pick, int st, int tot, int mn, int mx) {
  if (to_pick == 0) {
    ans += (l <= tot && tot <= r && mx - mn >= x);
    return;
  }

  for (int i = st; i < n; i++)
    solve(to_pick - 1, i + 1, tot + d[i], min(mn, d[i]), max(mx, d[i]));
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> l >> r >> x;
  for (int i = 0; i < n; i++)
    cin >> d[i];
  
  for (int to_pick = 2; to_pick <= n; to_pick++)
    solve(to_pick, 0, 0, 0x3f3f3f3f, 0);

  cout << ans;
}