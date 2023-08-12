#include <bits/stdc++.h>
using namespace std;

int n, m, ans;
int a[100'002];
unordered_map<int, bool> rec;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  while (m--) {
    int code, i, x; cin >> code >> i;
    switch (code) {
      case 1: cin >> x; a[i] |= (1 << x - 1); break;
      case 2: cin >> x; a[i] &= ~(1 << x - 1); break;
      case 3: a[i] &= ~(1 << 19); a[i] <<= 1; break;
      default: a[i] >>= 1; break;
    }
  }

  for (int i = 1; i <= n; i++) {
    if (rec[a[i]]) continue;
    rec[a[i]] = 1; ans++;
  }
  cout << ans;
}