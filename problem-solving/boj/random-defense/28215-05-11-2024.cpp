#include <bits/stdc++.h>
using namespace std;
using ll = long long;

pair<int, int> a[52];
int n, k, ans = 0x7f7f7f7f;

void solve(int remain, int idx, ll select) {
  if (remain == 0) {
    vector<int> selected;
    for (int i = 0; i < n; i++) {
      ll bit = ((ll) 1 << i);
      if (bit & select) selected.push_back(i);
    }
    int tmp = 0;
    for (int i = 0; i < n; i++) {
      int mn_dist = 0x7f7f7f7f;
      for (int j : selected) {
        int calc = abs(a[i].first - a[j].first) + abs(a[i].second - a[j].second);
        mn_dist = min(mn_dist, calc);
      }
      tmp = max(tmp, mn_dist);
    }
    ans = min(tmp, ans);
    return;
  }

  for (int i = idx; i < n; i++) {
    ll bit = (ll) 1 << i;
    solve(remain - 1, i + 1, select | bit);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    int x, y; cin >> x >> y;
    a[i] = {x, y};
  }
  solve(k, 0, 0);
  cout << ans;
}

