#include <bits/stdc++.h>
using namespace std;

int solve(int m) {
  int prv = 1;
  int cur = 1;
  int cnt = 2;
  while (prv != 1 || cur != 0) {
    int nxt = (prv + cur) % m;
    prv = cur;
    cur = nxt;
    cnt++;
  }
  return cnt;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    int n, m; cin >> n >> m;
    cout << n << ' ' << solve(m) << '\n';
  }
}
