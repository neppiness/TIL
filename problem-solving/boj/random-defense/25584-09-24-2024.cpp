#include <bits/stdc++.h>
using namespace std;

const string ANS[] = {"NO", "YES"};
const int INF = 0x7f7f7f7f;

unordered_map<string, int> sum;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 0; i < 4 * n; i++) {
    for (int j = 0; j < 7; j++) {
      string s; cin >> s;
      if (s == "-") continue;
      switch (i % 4) {
        case 0:
          sum[s] += 4; break;
        case 1:
          sum[s] += 6; break;
        case 2:
          sum[s] += 4; break;
        default:
          sum[s] += 10;
      }
    }
  }
  int mn = INF, mx = 0;
  for (auto &entry : sum) {
    mx = max(mx, sum[entry.first]);
    mn = min(mn, sum[entry.first]);
  }
  cout << ANS[mn == INF || mx - mn <= 12];
}
