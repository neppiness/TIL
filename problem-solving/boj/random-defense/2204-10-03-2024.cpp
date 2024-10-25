#include <bits/stdc++.h>
using namespace std;

pair<string, string> s[1002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  while (n) {
    for (int i = 0; i < n; i++) {
      string os; cin >> os;
      string lc = os;
      for (char &c : lc)
        c = tolower(c);
      s[i] = {lc, os};
    }
    sort(s, s + n);
    cout << s[0].second << '\n';
    cin >> n;
  }
}
