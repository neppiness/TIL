#include <bits/stdc++.h>
using namespace std;

string s;
int idx;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> s;
  for (int i = 1; 1; i++) {
    string istr = to_string(i);
    for (char c : istr) {
      if (s[idx] == c) {
        idx++;
      }
      if (idx == s.size()) {
        break;
      }
    }
    if (idx != s.size()) continue;
    cout << i;
    return 0;
  }
}
