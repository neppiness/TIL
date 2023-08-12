#include <bits/stdc++.h>
using namespace std;

int ans = 0;

void solve(int cur, int tot) {
  if (cur == 0) {
    ans += (tot % 3 == 0);
    return;
  }
  for (int i = 0; i < 3; i++)
    solve(cur - 1, tot*10 + i);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  solve(n - 1, 1);
  solve(n - 1, 2);
  cout << ans;
}