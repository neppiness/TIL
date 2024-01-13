#include <bits/stdc++.h>
using namespace std;

const string PO[] = {"AAAA", "BB"};
string s, ans;

bool solve(int idx) { // idx = 시작 인덱스
  while (idx < s.size() && s[idx] == '.') {
    idx++;
  }
  if (idx == s.size()) {
    ans = s;
    return 1;
  }

  for (string p : PO) {
    bool is_valid = 1;
    for (int i = idx; i < idx + p.size(); i++) {
      if (i >= s.size()) is_valid = 0;
      if (s[i] == '.') is_valid = 0;
    }
    if (!is_valid) continue;
    for (int i = idx; i < idx + p.size(); i++) {
      s[i] = p[i - idx];
    }
    if (solve(idx + p.size())) return 1;
    for (int i = idx; i < idx + p.size(); i++) {
      s[i] = 'X';
    }
  }
  return 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> s;
  if (solve(0)) {
    cout << ans;
  } else {
    cout << -1;
  }
}
