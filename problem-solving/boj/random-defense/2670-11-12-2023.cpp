#include <bits/stdc++.h>
using namespace std;

double a[10'002];

double mx = 0;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cout.precision(3);
  cout << fixed;

  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mx = max(mx, a[i]);
  }

  double mul = 1;
  for (int i = 0; i < n; i++) {
    mul *= a[i];
    mx = max(mx, mul);
    if (mul < 1.0) mul = 1;
  }
  cout << round(mx * 1000) / 1000.0;
}
