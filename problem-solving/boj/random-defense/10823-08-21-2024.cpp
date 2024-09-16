#include <bits/stdc++.h>
using namespace std;

vector<string> split(string &s) {
  vector<string> ret;
  int pos = 0;
  while (pos < s.length()) {
    int nxt = s.find(",", pos);
    if (nxt == -1) nxt = s.length();
    string ss = s.substr(pos, nxt - pos);
    ret.push_back(ss);
    pos = nxt + 1;
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s = "";
  string ss;
  while (getline(cin, ss))
    s += ss;
  vector<string> s_list = split(s);
  int ans = 0;
  for (string str : s_list)
    ans += stoi(str);
  cout << ans;
}
