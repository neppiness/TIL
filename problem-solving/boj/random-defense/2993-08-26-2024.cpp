#include <bits/stdc++.h>
using namespace std;

set<string> s_set;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s; cin >> s;
  int n = s.size();
  for (int i = 1; i < n; i++)
    for (int j = i + 1; j < n; j++) {
      string ss1 = s.substr(0, i);
      string ss2 = s.substr(i, j - i);
      string ss3 = s.substr(j);
      reverse(ss1.begin(), ss1.end());
      reverse(ss2.begin(), ss2.end());
      reverse(ss3.begin(), ss3.end());
      s_set.insert(ss1 + ss2 + ss3);
    }
  cout << *(s_set.begin());
}
