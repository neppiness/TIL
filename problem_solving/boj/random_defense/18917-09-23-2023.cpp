#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int q; cin >> q;
  ll sum = 0;
  int xor_res = 0;
  while (q--) {
    int cmd; cin >> cmd;
    int x;
    switch (cmd) {
      case 1:
        cin >> x;
        sum += x;
        xor_res ^= x;
        break;
      case 2:
        cin >> x;
        sum -= x;
        xor_res ^= x;
        break;
      case 3:
        cout << sum << '\n';
        break;
      default:
        cout << xor_res << '\n';
        break;
    }
  }
}
