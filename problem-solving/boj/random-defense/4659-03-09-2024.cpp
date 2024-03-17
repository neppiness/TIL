#include <bits/stdc++.h>
using namespace std;

const string VOWELS = "aeiou";
string s;

bool solve() {
  bool has_vowel = 0;
  int v_cnt = 0; // 연속된 모음 개수
  int c_cnt = 0; // 연속된 자음 개수
  char prv = 0;
  for (char c : s) {
    int pos = VOWELS.find(c);
    if (pos != -1) { 
      has_vowel = 1;
      c_cnt = 0;
      v_cnt++;
    } else {
      c_cnt++;
      v_cnt = 0;
    }
    if (c_cnt >= 3 || v_cnt >= 3) return 0;
    if (c != 'e' && c != 'o' && prv == c) {
      return 0;
    }
    prv = c;
  }
  return has_vowel;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> s;
  while (s != "end") {
    bool is_acceptable = solve();
    cout << "<" << s << "> "; 
    if (is_acceptable) {
      cout << "is acceptable.\n";
    } else {
      cout << "is not acceptable.\n";
    }
    cin >> s;
  }
}
