#include <bits/stdc++.h>
using namespace std;

int n, l;
tuple<int, int, int> tr[102];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> l;
  for (int i = 0; i < n; i++) {
    int d, r, g;
    cin >> d >> r >> g;
    tr[i] = {d, r, g};
  }

  int ans = 0, idx = 0;
  for (int pr = 0; pr < l; pr++, ans++) {
    if (idx == n) continue;
    auto [d, r, g] = tr[idx];
    if (d == pr) {
      if (ans % (r + g) < r) {
        ans += r - (ans % (r + g));       
      }
      idx++;
    }
  }
  cout << ans;
}
