#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  for (int i = 1; i <= t; i++) {
    ll n, m; cin >> n >> m;
    cout << "Scenario #" << i << ":\n";
    cout << (n + m) * (m - n + 1) / 2 << '\n';
    cout << '\n';
  }
}
