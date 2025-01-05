#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const string ANS[] = {"NO", "YES"};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  while (n--) {
    ll x; cin >> x;
    bool is_key = 1;
    for (int i = 2; i <= 1'000'000; i++) {
      if (x % i) continue;
      is_key = 0;
      break;
    }
    cout << ANS[is_key] << '\n';
  }
}
