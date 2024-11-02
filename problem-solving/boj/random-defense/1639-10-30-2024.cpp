#include <bits/stdc++.h>
using namespace std;

int val[52];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s; cin >> s;
  for (int i = 0; i < s.size(); i++) {
    val[i] = s[i] - '0';
  }

  int ans = 0;
  for (int len = 1; len <= s.size() / 2; len++) {
    for (int st = 0; st < s.size() - 2 * len; st++) {
      int sum1 = 0;
      for (int i = st; i < st + len; i++)
        sum1 += val[i];
      int sum2 = 0;
      for (int i = st + len; i < st + 2 * len; i++)
        sum2 += val[i];
      if (sum1 == sum2) ans = max(ans, 2 * len);
    }
  }
  cout << ans;
}
