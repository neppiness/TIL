#include <bits/stdc++.h>
using namespace std;

unordered_map<char, bool> sc;

vector<string> split(string &s) {
  vector<string> ret;
  int pos = 0;
  while (pos < s.size()) {
    int nxt = s.find(' ', pos);
    if (nxt == -1) nxt = s.size();
    int len = nxt - pos;
    if (len) ret.push_back(s.substr(pos, len));
    pos = nxt + 1;
  }
  return ret;
}

void solve() {
  string s; getline(cin, s);
  vector<string> split_str = split(s);
  // 첫번째 단계, 첫 단어에서 발견되는 경우
  // 발견되면 출력하고 종료.
  bool is_found = 0;
  for (string &word : split_str) {
    char c = tolower(word[0]);
    if (sc[c]) continue;
    is_found = 1;
    sc[c] = 1;
    string w = word.substr(0, 1);
    string ss = "[" + w + "]";
    word.replace(0, 1, ss);
    break;
  }
  if (is_found) {
    for (string w : split_str) cout << w << ' ';
    cout << '\n'; return;
  }
  // 두번째 단계, 이제 단어들 싹 돌면서 shortcut으로
  // 등록되지 않은 게 있다면 씌워넣음.
  // 여기서 발견 안 되면 출력하고 땡.
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == ' ') continue;
    char c = tolower(s[i]);
    if (sc[c]) continue;
    sc[c] = 1;
    
    string w = s.substr(i, 1);
    string ss = "[" + w + "]";
    s.replace(i, 1, ss);
    break;
  }
  cout << s << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  cin.ignore();
  while (n--) solve();
}
