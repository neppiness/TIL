#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> um;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s; int ans = 0;
  for (int i = 0; i < 3; i++) {
    cin >> s;
    int code = (1 << i);
    for (int len = 1; len <= s.length(); len++) {
      for (int st = 0; st + len <= s.length(); st++) {
        string ss = s.substr(st, len);
        um[ss] = (um[ss] | code);
        if (um[ss] == 7) ans = max(ans, len);
      }
    }
  }
  cout << ans;
}