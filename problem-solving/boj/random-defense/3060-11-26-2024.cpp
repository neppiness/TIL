#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    int init = 0;
    for (int i = 0; i < 6; i++) {
      int x; cin >> x;
      init += x;
    }

    int cnt = 1;
    int sum = init;
    while (sum <= n) {
      cnt++;
      sum *= 4;
    }
    cout << cnt << '\n';
  }
}
