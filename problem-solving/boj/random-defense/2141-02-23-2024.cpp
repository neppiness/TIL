#include <bits/stdc++.h>
using namespace std;
using ll = long long;

pair<ll, ll> input[100'002];
ll total_a;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    ll x, a; cin >> x >> a;
    input[i] = {x, a};
    total_a += a;
  }

  sort(input, input + n);

  for (int i = 0; i < n; i++) {
    total_a -= input[i].second * 2;
    if (total_a > 0) continue;
    cout << input[i].first;
    return 0;
  }
}
