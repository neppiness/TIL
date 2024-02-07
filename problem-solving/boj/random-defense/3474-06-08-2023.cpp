#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n; cin >> n;
  int fives = 5, cnt = 0;
  while (n / fives) {
    cnt += n / fives;
    fives *= 5;
  }
  cout << cnt << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) solve();
}