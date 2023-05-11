#include <bits/stdc++.h>
using namespace std;

const int LIM = 80;

string s, input; 
vector<string> splitted_input;

vector<string> split(string& s, string sep) {
  vector<string> ret;
  int pos = 0;
  while (pos < s.size()) {
    int nxt_pos = s.find(sep, pos);
    if (nxt_pos == -1) nxt_pos = s.size();
    if (nxt_pos - pos > 0)
      ret.push_back(s.substr(pos, nxt_pos - pos));
    pos = nxt_pos + sep.size();
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  while (getline(cin, s)) input += ' ' + s;
  for (char& c : input)
    if (c == '\t') c = ' ';

  splitted_input = split(input, " ");
  int cnt = 0;
  for (auto& str : splitted_input) {
    string tagchk = str.substr(0, 4);
    if (tagchk != "<br>" && tagchk != "<hr>") {
      if (cnt + str.size() > LIM) { cout << '\n'; cnt = 0; }
      cout << str; cnt += str.size();
      if (cnt < LIM) { cout << ' '; cnt++; }
    } else {
      if (tagchk == "<hr>") {
        if (cnt) cout << '\n';
        int no = LIM;
        while (no--) cout << '-';
      }
      cout << '\n'; cnt = 0;
    }
  }
  cout << '\n';
}