#include <bits/stdc++.h>
using namespace std;

string s;

bool solve() {
  int i = 0;
  while (i != s.length()) {
    if (s[i] == '1') { // 1패턴 확인
      if (i + 3 >= s.length()) return 0;
      if (s[i + 1] == '1' || s[i + 2] == '1') return 0;
      i++;
      while (s[i] == '0') i++;
      if (i == s.length()) return 0;
      while (s[i] == '1') i++;
    } else { // 2패턴 확인
      if (i + 1 == s.length()) return 0;
      if (s[i + 1] == '0') {
        if (i == 0) return 0;
        if (i < 2 || s[i - 2] != '1') return 0;
        i--; continue;
      }
      i += 2;
    }
  }
  return 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> s;
  if (solve()) cout << "SUBMARINE";
  else cout << "NOISE";
}