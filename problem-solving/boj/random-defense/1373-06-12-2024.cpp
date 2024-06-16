#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s; cin >> s;
  int mod = s.length() % 3;
  int tot = 0;
  for (int i = 0; i < mod; i++) {
    tot *= 2;
    tot += (s[i] == '1');
  }
  if (mod != 0) {
    cout << tot;
  }
  tot = 0;
  int cnt = 0;
  for (int i = mod; i < s.length(); i++) {
    cnt++;
    tot *= 2;
    tot += (s[i] == '1');
    if (cnt == 3) {
      cout << tot;
      tot = 0;
      cnt = 0;
    }
  }
}
