#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  string ans;
  int mx_cnt = 0;
  int pk = 0;
  while (n--) {
    string s; cin >> s;
    int k, m; cin >> k >> m;
    int cnt = 0;
    while (m - k >= 0) {
      pk++;
      cnt++;
      m -= k;
      m += 2;
    }
    if (mx_cnt >= cnt) {
      continue;
    }
    mx_cnt = cnt;
    ans = s;
  }
  cout << pk << '\n' << ans;
}
