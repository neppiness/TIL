#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll ss[1'000'002];
ll s[1'000'002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    s[i] = s[i - 1] + x;
    ss[i] = ss[i - 1] + x * x;
  }

  ll mx = 0;
  for (int k = 1; k <= n - 1; k++) {
    ll res = ss[k] * (s[n] - s[k]);
    mx = max(mx, res);
  }
  cout << mx;
}
