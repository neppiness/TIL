#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> info;
vector<int> v;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    while (n--) {
      string s; int d;
      cin >> s >> d;
      if (info[s] == 0) {
        info[s] = d;
      } else {
        info[s] = min(info[s], d);
      }
    }
    for (auto &pr : info)
      v.push_back(pr.second);
    sort(v.begin(), v.end());

    for (int i : v)
      cout << i << ' ';
    cout << '\n';
    v.clear();
    info.clear();
  }
}
