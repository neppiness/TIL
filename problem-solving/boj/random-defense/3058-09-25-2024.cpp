#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    int sum = 0, mn = 102;
    for (int i = 0; i < 7; i++) {
      int x; cin >> x; 
      if (x % 2) continue;
      sum += x;
      mn = min(mn, x);
    }
    cout << sum << ' ' << mn << '\n';
  }
}

