#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  vector<tuple<int, int, int, string>> members;
  while (n--) {
    string name; int d, m, y;
    cin >> name >> d >> m >> y;
    members.push_back({y, m, d, name});
  }
  sort(members.begin(), members.end());
  string ans1, ans2;
  tie(ignore, ignore, ignore, ans1) = members[0];
  tie(ignore, ignore, ignore, ans2) = members[members.size() - 1];
  cout << ans2 << '\n' << ans1;
}
