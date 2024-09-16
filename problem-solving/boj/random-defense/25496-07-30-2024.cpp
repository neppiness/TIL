#include <bits/stdc++.h>
using namespace std;

int a[1002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int p, n; cin >> p >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  sort(a, a + n);

  int ans = 0;
  if (p == 200) {
    cout << ans;
    return 0;
  }
  for (int i = 0; i < n; i++) {
    p += a[i];
    ans++;
    if (p >= 200) break;
  }
  cout << ans;
}
