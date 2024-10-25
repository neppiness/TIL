#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int a[100'002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    ll b; cin >> a[i] >> b;
    sum += b;
  }
  sort(a, a + n);
  for (ll i = 0; i < n; i++) {
    sum += a[i] * (i + 1);
  }
  cout << sum;
}
