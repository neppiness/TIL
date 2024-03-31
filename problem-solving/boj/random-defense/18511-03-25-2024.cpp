#include <bits/stdc++.h>
using namespace std;

int a[3];
int n, m, ans;

void solve(int to_pick, int sum) {
  if (sum <= n) ans = max(ans, sum);
  if (to_pick == 0) {
    return;
  }

  for (int i = 0; i < m; i++) {
    solve(to_pick - 1, sum * 10 + a[i]);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i < m; i++)
    cin >> a[i];

  solve(to_string(n).length(), 0);
  cout << ans;
}
