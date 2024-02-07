#include <bits/stdc++.h>
using namespace std;

int solve() {
  int n;
  int w = 0, b = 0; // st 기준
  string st, en;
  cin >> n >> st >> en;
  
  for (int i = 0; i < n; i++) {
    if (st[i] == en[i]) continue;
    w += (st[i] == 'W');
    b += (st[i] == 'B');
  }
  int mn = min(w, b); // min번 교환을 수행.
  int mx = max(w, b);
  int flip = mx - mn; // 교환이 안 된 남은 수는 뒤집기
  return flip + mn;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) cout << solve() << '\n';
}
