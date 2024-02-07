#include <bits/stdc++.h>
using namespace std;

string s[2];
int cnt[2];

int solve() {
  memset(cnt, 0, sizeof(cnt));
  cin >> s[0] >> s[1];
  
  for (int i = 0; i < 2; i++) {
    for (char c : s[i]) {
      if (c == '0') continue;
      cnt[i]++;
    }
  }

  if (cnt[0] > cnt[1]) {
    swap(s[0], s[1]);
    swap(cnt[0], cnt[1]);
  }

  int diff = cnt[1] - cnt[0];
  int ans = diff;
  for (int i = 0; i < s[0].size(); i++) {
    if (!diff) break;
    if (s[1][i] == '1' && s[0][i] == '0') {
      s[0][i] = '1';
      diff--;
    } 
  }

  for (int i = 0; i < s[0].size(); i++) {
    if (s[0][i] != s[1][i]) diff++;
  }
  ans += (diff / 2);
  return ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    cout << solve() << '\n';
  }
}
