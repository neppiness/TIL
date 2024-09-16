#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> x_cnt, y_cnt;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    int x, y; cin >> x >> y;
    x_cnt[x]++; y_cnt[y]++;
  }
  
  int ans = 0;
  for (auto [x, cnt] : x_cnt)
    ans += (cnt > 1);

  for (auto [y, cnt] : y_cnt)
    ans += (cnt > 1);

  cout << ans;
}
