#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, k;
int a[10'002];

bool isValid(ll cur) {
  ll cnt = 0;
  for (int i = 0; i < n; i++)
    cnt += a[i] / cur;
  return cnt >= k;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  ll st = 0;
  ll en = ((ll)1 << 50) - 1;
  while (st < en) {
    ll mid = (st + en) / 2 + 1;
    if (isValid(mid)) st = mid;
    else en = mid - 1;
  }
  cout << st;
}
