#include <bits/stdc++.h>
using namespace std;

string s, t;
unordered_map<string, bool> cache;
unordered_map<string, bool> is_checked;

bool solve(string str) {
  bool &ret = cache[str];
  if (is_checked[str]) return ret;
  if (str.size() == s.size()) return ret = (str == s);

  is_checked[str] = 1;
  if (str[str.size() - 1] == 'A') {
    string ss = str; ss.pop_back();
    ret |= solve(ss);
  }
  if (str[0] == 'B') {
    string rs = str;
    reverse(rs.begin(), rs.end());
    rs.pop_back();
    ret |= solve(rs);
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> s >> t;
  cout << solve(t);
}