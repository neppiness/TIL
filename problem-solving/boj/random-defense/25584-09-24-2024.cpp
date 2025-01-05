#include <bits/stdc++.h>
using namespace std;

const string ANS[] = {"No", "Yes"};
const int INF = 0x7f7f7f7f;
const int TIME[] = {4, 6, 4, 10};

unordered_map<string, int> sum;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 0; i < 4 * n; i++) {
    int t = TIME[i % 4];
    for (int j = 0; j < 7; j++) {
      string s; cin >> s;
      if (s == "-") continue;
      sum[s] += t;
    }
  }
  int mx = 0, mn = INF;
  for (auto s : sum) {
    mx = max(mx, s.second);
    mn = min(mn, s.second);
  }
  cout << ANS[mx - mn <= 12];
}
