#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m, a[100'002];

bool solve(ll x) {
  ll cnt = 0;
  for (int i = 0; i < n; i++) {
    cnt += x / a[i];
    if (cnt >= m) return 1;
  }
  return 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  ll st = 0, en = 1e18;
  while (st < en) {
    ll mid = (st + en) / 2;
    if (solve(mid)) en = mid;
    else st = mid + 1;
  }
  cout << st;
}