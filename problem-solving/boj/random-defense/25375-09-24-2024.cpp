#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    ll g, s; cin >> g >> s;
    cout << (s % g == 0) << '\n';
  }
}
