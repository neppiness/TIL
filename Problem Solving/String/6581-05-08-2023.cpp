#include <bits/stdc++.h>
using namespace std;

string s, input; 
vector<string> splitted_input;

vector<string> split(string &s, string sep) {
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
  for (auto str : splitted_input) {
    if (str != "<br>" && str != "<hr>") {
      if (cnt + str.size() > 80) { cnt = 0; cout << '\n'; }
      for (char c : str) cout << c;
      cnt += str.size();
      if (cnt < 80) { cout << ' '; cnt++; }
      else { cout << '\n'; }
    } else {
      if (str == "<br>") cout << '\n';
      if (str == "<hr>") {
        if (cnt) cout << '\n';
        int no = 80;
        while (no--) cout << '-';
        cout << '\n';
      }
      cnt = 0;
    }
  }
}
/*
getline을 통해 입력 받은 s를 input 문자열에 덧붙인다.
*/ 