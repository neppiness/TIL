#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> v;

bool is_not_mixed(int t) {
  int prv = -0x7f7f7f7f;
  for (auto [x, h] : v) {
    int dw = t;
    if (h - 2 * dw < 0) {
      dw = (h - 1) / 2;
    }
    int cx1 = x - dw;
    if (cx1 <= prv) {
      return 0;
    }
    prv = x + dw;
  }
  return 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int mxh = 0;
  while (n--) {
    int x, h; cin >> x >> h;
    v.push_back({x, h});
    mxh = max(mxh, h);
  }
  sort(v.begin(), v.end());

  int st = 0, en = mxh / 2;
  while (st < en) {
    int mid = (st + en) / 2 + 1;
    if (is_not_mixed(mid)) {
      st = mid;
    } else {
      en = mid - 1;
    }
  }
  if (is_not_mixed(st + 1)) {
    cout << "forever";
  } else {
    cout << st;
  }
}
