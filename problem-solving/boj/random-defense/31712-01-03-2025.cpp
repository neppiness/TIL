#include <bits/stdc++.h>
using namespace std;

int t[3], d[3];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 0; i < 3; i++)
    cin >> t[i] >> d[i];

  int h; cin >> h;
  int ans = 0;
  while (1) {
    for (int i = 0; i < 3; i++) {
      if (ans % t[i] != 0) continue;
      h -= d[i];
    }
    if (h <= 0) {
      cout << ans;
      return 0;
    }
    ans++;
  }
}
