#include <bits/stdc++.h>
using namespace std;

vector<string> split(string &s, string del) {
  vector<string> ret;
  int pos = 0;
  int end = s.find(';');
  while (pos < end) {
    int nxt = s.find(del, pos);
    if (nxt == -1) nxt = end;
    if (nxt - pos != 0)
      ret.push_back(s.substr(pos, nxt - pos));
    pos = nxt + del.size();
  }
  return ret;
}

void print(string &var) {
  int end = var.size() - 1;
  while (!isalpha(var[end])) {
    if (var[end] == ']') {
      cout << "[]"; end -= 2;
    } else {
      cout << var[end--];
    }
  }
  cout << ' ' << var.substr(0, end + 1) << ';';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;
  getline(cin, s);

  int fir_blank = s.find(" ");
  string basic = s.substr(0, fir_blank);

  fir_blank++;
  string ss = s.substr(fir_blank);
  vector<string> split_s = split(ss, ", ");

  for (string var : split_s) {
    cout << basic;
    print(var);
    cout << '\n';
  }
}
