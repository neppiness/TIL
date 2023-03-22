#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll x, y; cin >> x >> y;
  ll z = 100 * y / x;

  ll num = (100*y - (z + 1)*x);
  ll deno = z - 99;

  if(z >= 99) {
    cout << -1;
  } else if(num % deno == 0) {
    cout << num / deno;
  } else {
    cout << num / deno + 1;
  }
}