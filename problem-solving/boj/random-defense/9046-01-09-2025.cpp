#include <bits/stdc++.h>
using namespace std;

int cnt[26];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  cin.ignore();
  while (t--) {
    memset(cnt, 0, sizeof(cnt));
    string s;
    getline(cin, s);

    int mx = 0;
    for (char c : s) {
      if (c == ' ') continue;
      mx = max(mx, ++cnt[c - 'a']);
    }
    int chk = 0;
    char ans;
    for (int i = 0; i < 26; i++) {
      if (cnt[i] != mx) continue;
      chk++;
      ans = (char)(i + 'a');
    }
    if (chk == 1) {
      cout << ans << '\n';
    } else {
      cout << '?' << '\n';
    }
  }
}
