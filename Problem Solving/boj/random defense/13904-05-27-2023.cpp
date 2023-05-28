#include <bits/stdc++.h>
using namespace std;

int n, is_done[1002];
pair<int, int> hw[1002];

bool cmp(pair<int, int> &a, pair<int, int> &b) {
  if (a.first == b.first)
    return a.second > b.second;
  return a.first > b.first;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) {
    int due, score; cin >> due >> score;
    hw[i] = {due, score};
  }

  sort(hw, hw + n, cmp);
  
  int ans = 0;
  for (int day = n; day > 0; day--) {
    int tmp_idx = -1, tmp_score = 0;
    for (int i = 0; i < n; i++) {
      if (is_done[i]) continue;
      auto [due, score] = hw[i];
      if (due < day) continue;
      if (score <= tmp_score) continue;
      tmp_score = score;
      tmp_idx = i;
    }
    if (tmp_idx == -1) continue;
    is_done[tmp_idx] = 1;
    ans += tmp_score;
  }
  cout << ans;
}