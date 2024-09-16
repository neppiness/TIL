#include <bits/stdc++.h>
using namespace std;

pair<int, int> coord[102];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, r; cin >> n >> r;
  int r_sq = r * r;
  for (int i = 0; i < n; i++) {
    int x, y; cin >> x >> y;
    coord[i] = {x, y};
  }

  int mx_cnt = 0;
  pair<int, int> ans;
  for (int i = -100; i <= 100; i++) {
    for (int j = -100; j <= 100; j++) {
      int cnt = 0;
      for (int k = 0; k < n; k++) {
        auto [x, y] = coord[k];
        int dist_sq = (x - i) * (x - i) + (y - j) * (y - j);
        cnt += (dist_sq <= r_sq);
      }
      if (cnt > mx_cnt) {
        ans = {i, j};
      }
      mx_cnt = max(mx_cnt, cnt);
    }
  }
  cout << ans.first << ' ' << ans.second;
}
