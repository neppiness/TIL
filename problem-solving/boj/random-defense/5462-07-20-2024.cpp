#include <bits/stdc++.h>
using namespace std;

int n, t, p;
int sc[2002];
bool re[2002][2002];
vector<tuple<int, int, int>> a; // 점수, 문제 수, -id

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> t >> p;
  for (int id = 1; id <= n; id++) {
    for (int pr = 1; pr <= t; pr++) {
      bool x; cin >> x;
      re[id][pr] = x;
      sc[pr] += (!x);
    }
  }

  for (int id = 1; id <= n; id++) {
    int tot = 0, no = 0;
    for (int pr = 1; pr <= t; pr++) {
      bool x = re[id][pr];
      if (!x) continue;
      tot += sc[pr];
      no++;
    }
    a.push_back({tot, no, -id});
  }
  sort(a.rbegin(), a.rend());
  for (int i = 0; i < n; i++) {
    auto [tot, no, id] = a[i];
    if (-id != p) continue;
    cout << tot << ' ' << i + 1;
    return 0;
  }
}
