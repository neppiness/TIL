#include <bits/stdc++.h>
using namespace std;

vector<pair<string, int>> q[302];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int p, n; cin >> p >> n;
  while (p--) {
    int lv; string nm;
    cin >> lv >> nm;
    for (int i = 0; i < 300; i++) {
      if (q[i].size() == n) continue;
      if (q[i].size()) {
        auto [ld_nm, ld_lv] = q[i][0];
        if (ld_lv - 10 > lv || ld_lv + 10 < lv) {
          continue;
        }
      }
      q[i].push_back({nm, lv});
      break;
    }
  }
  for (int i = 0; i < 300; i++) {
    if (!q[i].size()) continue;
    if (q[i].size() == n) {
      cout << "Started!" << '\n';
    } else {
      cout << "Waiting!" << '\n';
    }
    sort(q[i].begin(), q[i].end());
    for (auto [nm, lv] : q[i]) {
      cout << lv << ' ' << nm << '\n';
    }
  }
}
