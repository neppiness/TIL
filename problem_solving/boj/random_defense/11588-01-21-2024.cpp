#include <bits/stdc++.h>
using namespace std;

int n;
int po[10'002];

int solve() {
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> po[i];
  int cur = 1;
  for (int k = 1; k <= n; k++) {
    cur = po[cur];
    if (cur == n) return k;
  }
  return 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--)
    cout << solve() << '\n';
}
