#include <bits/stdc++.h>
using namespace std;

vector<string> split(string &s) {
  vector<string> ret;
  int pos = 0;
  int n = s.size();
  while (pos < n) {
    int nxt1 = s.find('A', pos + 1);
    if (nxt1 == -1) nxt1 = n;
    int nxt2 = s.find('B', pos + 1);
    if (nxt2 == -1) nxt2 = n;
    int nxt3 = s.find('C', pos + 1);
    if (nxt3 == -1) nxt3 = n;

    int nxt = min(nxt1, nxt2);
    nxt = min(nxt, nxt3);

    string ss = s.substr(pos, nxt - pos);
    ret.push_back(ss);
    pos = nxt;
  }
  return ret;
}

bool is_lower(string &g) { // C+, C0, C-;
  return g == "C+" || g == "C0" || g == "C" || g == "C-";
}

bool is_low(string &g) { // B0, B-
  return g == "B0" || g == "B" || g == "B-";
}

bool is_mid(string &g) { // A-, B+
  return g == "A-" || g == "B+";
}

bool is_a0(string &g) { // A0
  return g == "A" || g == "A0";
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  string s; cin >> s;
  vector<string> gr = split(s);
  for (int i = 0; i < n; i++) {
    if (is_lower(gr[i])) {
      cout << 'B';
    } else if (is_low(gr[i])) {
      if (i == 0 || is_lower(gr[i - 1])) {
        cout << 'D';
      } else {
        cout << 'B';
      }
    } else if (is_mid(gr[i])) {
      if (i == 0 || is_lower(gr[i - 1]) || is_low(gr[i - 1])) {
        cout << 'P';
      } else {
        cout << 'D';
      }
    } else if (is_a0(gr[i])) {
      if (i == 0 || is_lower(gr[i - 1]) || is_low(gr[i - 1]) || is_mid(gr[i - 1])) {
        cout << 'E';
      } else {
        cout << 'P';
      }
    } else {
      cout << 'E';
    }
  }
}
