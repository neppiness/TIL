#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int a[500'002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  ll ans = 0, cur = 0;
  for (int i = n - 1; i >= 0; i--) {
    cur++;
    if (cur > a[i]) cur = a[i];
    ans += cur;
  }
  cout << ans;
}
