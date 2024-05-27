#include <bits/stdc++.h>
using namespace std;

const int INF = 0x7f7f7f7f;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, b, h, w;
  cin >> n >> b >> h >> w;

  int ans = INF;
  while (h--) {
    int pr; cin >> pr;
    for (int i = 0; i < w; i++) {
      int x; cin >> x;
      if (x < n) continue;
      int tot = pr * n;
      if (tot > b) continue;
      ans = min(ans, tot);
    }
  }

  if (ans == INF) {
    cout << "stay home";
  } else {
    cout << ans;
  }
}
