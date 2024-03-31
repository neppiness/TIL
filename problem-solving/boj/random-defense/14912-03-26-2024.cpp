#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    string s = to_string(i);
    for (char c : s) {
      ans += ((c - '0') == m);
    }
  }
  cout << ans;
}
