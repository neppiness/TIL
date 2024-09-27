#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 10; n / i != 0; i *= 10) {
    double x = n * 1.0 / i;
    x = round(x) * i;
    n = x;
  }
  cout << n;
}
