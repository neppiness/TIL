#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  int s[102];
  fill(s, s + n, m);

  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans += s[i] / n;
    if (s[i] % n == 0) ans--;
    int rest = s[i] % n;
    if (rest) s[i + 1] += rest;
  }
  cout << ans;
}