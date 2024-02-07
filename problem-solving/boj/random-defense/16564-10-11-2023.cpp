#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, k;
int a[1'000'002];

bool solve(ll x) {
  ll tot = 0;
  for (int i = 0; i < n; i++)
    tot += max(x - a[i], (ll)0);
  return tot <= k;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n >> k;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  ll st = 0, en = 2e9;
  while (st < en) {
    ll mid = (st + en) / 2 + 1;
    if (solve(mid)) st = mid;
    else en = mid - 1;
  }
  cout << st;
}
