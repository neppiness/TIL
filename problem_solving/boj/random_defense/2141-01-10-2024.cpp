#include <bits/stdc++.h>
using namespace std;
using ll = long long;

pair<ll, ll> b[100'002];
ll sum[100'002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    ll a, x;
    cin >> x >> a;
    b[i] = {x, a};
  }
  sort(b, b + n);
  for (int i = 1; i <= n; i++)
    sum[i] += sum[i - 1] + b[i].second;

  for (int i = 1; i <= n; i++) {
    ll pos_left = sum[i - 1];
    ll neg_left = sum[n] - sum[i - 1];
    ll pos_right = sum[i];
    ll neg_right = sum[n] - sum[i];
    ll left = pos_left - neg_left;
    ll right = pos_right - neg_right;
    if (left < 0 && right >= 0) {
      cout << b[i].first;
      return 0;
    }
  }
}
