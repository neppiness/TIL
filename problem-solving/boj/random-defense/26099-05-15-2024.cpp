#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll n; cin >> n;
  ll no5 = n / 5, no3 = 0;

  ll rest = n % 5;
  switch (rest) {
    case 1:
      no5--;
      no3 = 2;
      break;
    case 2:
      no5 -= 2;
      no3 = 4;
      break;
    case 3:
      no3 = 1;
      break;
    case 4:
      no5--;
      no3 = 3;
      break;
    default:
      no3 = 0;
      break;
  }

  ll ans = no3 + no5;
  if (no5 < 0) {
    ans = -1;
  }
  cout << ans;
}
