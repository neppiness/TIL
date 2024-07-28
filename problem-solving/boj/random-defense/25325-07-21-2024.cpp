#include <bits/stdc++.h>
using namespace std;

const string DEL = " ";

unordered_map<string, int> note;

vector<string> split(string& s) {
  vector<string> ret;
  int pos = 0;
  while (pos < s.length()) {
    int nxt = s.find(DEL, pos);
    if (nxt == -1) nxt = s.length();
    ret.push_back(s.substr(pos, nxt - pos));
    pos = nxt + DEL.length();
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  cin.ignore();
  string s; getline(cin, s);
  vector<string> students = split(s);
  while (n--) {
    getline(cin, s);
    vector<string> po = split(s);
    for (string &p : po)
      note[p]++;
  }

  vector<pair<int, string>> v;
  for (string &st : students)
    v.push_back({-note[st], st});
  sort(v.begin(), v.end());
  for (auto [sc, st] : v) {
    cout << st << ' ' << -sc << '\n';
  }
}
