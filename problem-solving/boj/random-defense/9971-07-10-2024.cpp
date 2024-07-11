#include <bits/stdc++.h>
using namespace std;

void solve(string s) {
  for (char c : s) {
    if (c < 65 || c > 90) {
      cout << c;
      continue;
    }
    int a = c + 21;
    if (a > 90) a -= 26;
    cout << (char)a;
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;
  getline(cin, s);
  while (s != "ENDOFINPUT") {
    getline(cin, s);
    solve(s);
    getline(cin, s);
    getline(cin, s);
  }
}
