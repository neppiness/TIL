#include <bits/stdc++.h>
using namespace std;

int INF = 0x7f7f7f7f;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, t; cin >> n >> t;
  int ans = INF;
  while (n--) {
    int s, it, c;
    cin >> s >> it >> c;
    for (int i = 0; i < c; i++) {
      int x = (s + i * it) - t; 
      if (x >= 0) ans = min(ans, x);
    }
  }
  if (ans == INF) ans = -1;
  cout << ans;
}
