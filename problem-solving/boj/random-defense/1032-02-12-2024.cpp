#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  string ans;
  cin >> ans;
  while (--n) {
    string s; cin >> s;
    for (int i = 0; i < s.size(); i++) {
      if (ans[i] == s[i]) continue;
      ans[i] = '?';
    }
  }
  cout << ans;
}
