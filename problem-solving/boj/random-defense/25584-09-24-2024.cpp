#include <bits/stdc++.h>
using namespace std;

const string ANS[] = {"NO", "YES"};

unordered_map<string, int> sum;
vector<pair<string, int>> note;

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
          note.push_back({s, 4});
          break;
        case 1:
          note.push_back({s, 6});
          break;
        case 2:
          note.push_back({s, 4});
          break;
        default:
          note.push_back({s, 10});
      }
    }
  }

  for (const auto &pr : note)
    sum[pr.first] = 0;

  for (const auto &pr : note)
    sum[pr.first] += pr.second;

  int mx = 0, mn = 0x7f7f7f7f;
  for (const auto &pr : sum) {
    mx = max(pr.second, mx);
    mn = min(pr.second, mn);
  }
  cout << ANS[mn == 0x7f7f7f7f || mx - mn <= 12];
}
