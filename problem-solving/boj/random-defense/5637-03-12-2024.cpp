#include <bits/stdc++.h>
using namespace std;

vector<string> split(string &s) {
  int pos = 0;
  vector<string> ret;
  while (pos < s.size()) {
    int nxt = s.find(" ", pos);
    if (nxt == -1) nxt = s.size();
    int len = nxt - pos;
    if (len)
      ret.push_back(s.substr(pos, len));
    pos = nxt + 1;
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s, input;
  while (cin >> s)
    input += s + " ";
  
  for (char &c : input) {
    if (isupper(c) || islower(c) || c == '-')
      continue;
    c = ' ';
  }
  vector<string> ss = split(input);
  string ans = "";
  for (int i = 0; i < ss.size() - 1; i++) {
    if (ans.size() >= ss[i].size()) 
      continue;
    ans = ss[i];
  }
  for (char c : ans) {
    cout << (char) tolower(c);
  }
}
