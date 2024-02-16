#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  string s; cin >> s;
  int rcnt = 0, bcnt = 0;
  for (char c : s) {
    rcnt += (c == 'R');
    bcnt += (c == 'B');
  }

  int ans = n;
  int idx = 0;
  while (idx < n) {
    if (s[idx] != 'R') break;
    idx++;
  }
  ans = min(ans, rcnt - idx);
  
  idx = 0;
  while (idx < n) {
    if (s[idx] != 'B') break;
    idx++;
  }
  ans = min(ans, bcnt - idx);

  idx = n - 1;
  while (idx >= 0) {
    if (s[idx] != 'R') break;
    idx--;
  }
  ans = min(ans, rcnt - (n - 1 - idx));

  idx = n - 1;
  while (idx >= 0) {
    if (s[idx] != 'B') break;
    idx--;
  }
  ans = min(ans, bcnt - (n - 1 - idx));
  cout << ans;
}
