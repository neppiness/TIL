#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll sum[1002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  
  ll tot = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int x; cin >> x;
      sum[i] += x;
    }
    tot += sum[i];
  }

  if (n == 2) {
    cout << 1 << ' ' << 1;
    return 0;
  }
  
  ll all_sum = tot / (2 * n - 2);
  for (int i = 0; i < n; i++) {
    ll x = (sum[i] - all_sum) / (n - 2);
    cout << x << ' ';
  }
}
