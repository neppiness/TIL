#include <bits/stdc++.h>
using namespace std;

bool solve(string &s) {
  for (int d = 1; d < s.size(); d++) {
    unordered_map<string, bool> chk;
    for (int i = 0; i < s.size() - d; i++) {
      string ss = "";
      ss += s[i];
      ss += s[i + d];
      if (chk[ss]) return 0;
      chk[ss] = 1;
    }
  }
  return 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;
  cin >> s;
  while (s[0] != '*') {
    cout << s << ' ';
    if (solve(s)) {
      cout << "is surprising." << '\n';
    } else {
      cout << "is NOT surprising." << '\n';
    }
    cin >> s;
  }
}
