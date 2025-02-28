#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    ll a, b; cin >> a >> b;
    cout << (a + b) * (a + b) * (a + b - 1) / 2 << '\n';
  }
}
