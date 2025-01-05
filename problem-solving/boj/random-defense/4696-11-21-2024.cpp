#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cout.precision(2);
  cout << fixed;

  double n; cin >> n;
  while (n) {
    if (n == 1) {
      cout << 5.00 << '\n';
    } else {
      cout << (n * n * n * n * n - 1) / (n - 1) << '\n';
    }
    cin >> n;
  }
}
