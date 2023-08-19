#include <bits/stdc++.h>
using namespace std;

unordered_map<string, bool> memo;
string str;

vector<string> split(string s) {
  vector<string> ret;
  int pos = 0;
  while (pos < s.size()) {
    int nxt = s.find(',', pos);
    if (nxt == -1) nxt = s.size();
    string ss = s.substr(pos, nxt - pos);
    if (ss.size()) ret.push_back(ss);
    pos = nxt + 1;
  }
  return ret;

}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  while (n--) {
    cin >> str;
    memo[str] = 1;
  }
  while (m--) {
    cin >> str;
    vector<string> split_s = split(str);
    for (auto k : split_s) memo.erase(k);
    cout << memo.size() << '\n';
  }
}
