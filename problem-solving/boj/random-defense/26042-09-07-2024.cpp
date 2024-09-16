#include <bits/stdc++.h>
using namespace std;

deque<int> d;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int ans = 0;
  int last_no = 0x7f7f7f7f;
  while (n--) {
    int type; cin >> type;
    if (type == 1) {
      int x; cin >> x;
      d.push_back(x);
      if (d.size() < ans) continue;
      if (d.size() == ans) {
        last_no = min(last_no, d.back());
      } else {
        last_no = d.back();
      }
      ans = max(ans, (int) d.size());
    } else {
      d.pop_front();
    }
  }
  cout << ans << ' ' << last_no;
}
