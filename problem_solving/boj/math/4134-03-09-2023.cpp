#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  ll a; cin >> a;
  if(a == 0 || a == 1) {
    cout << 2 << '\n';
    return;
  }

  while(1) {
    bool is_found = 1;
    for(ll i = 2; i * i <= a; i++) {
      if(a % i != 0) continue;
      is_found = 0;
      break;
    }
    if(!is_found) { a++; continue; }
    cout << a << '\n';
    return;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  while(n--) solve();
}