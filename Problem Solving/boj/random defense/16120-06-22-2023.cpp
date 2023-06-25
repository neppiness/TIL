#include <bits/stdc++.h>
using namespace std;

string s;

bool solve() {
  int j = 0;
  for (int i = 0; i < s.size(); i++) {
    switch (j) {
      case 0:
        if (s[i] == 'A') return 0;
        break;
      case 1:
        if (s[i] == 'A') return 0;
        break;
      case 2:
        if (s[i] == 'P') { j = 0; i--; }
        break;
      default:
        if (s[i] == 'A') return 0;
        j = 0;
    }
    j++;
  }
  return (j == 1);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> s;
  if (solve()) cout << "PPAP";
  else cout << "NP";
}