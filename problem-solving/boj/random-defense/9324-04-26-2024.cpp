#include <bits/stdc++.h>
using namespace std;

string solve() {
  string s; cin >> s;
  int cnt[26] = {};
  for (int i = 0; i < s.size(); i++) {
    int idx = s[i] - 'A';
    cnt[idx]++;
    if (cnt[idx] == 3) {
      if (i + 1 == s.size() || s[i + 1] != s[i]) {
        return "FAKE";
      }
      i++;
      cnt[idx] = 0;
    }
  }
  return "OK";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--)
    cout << solve() << '\n';
}
