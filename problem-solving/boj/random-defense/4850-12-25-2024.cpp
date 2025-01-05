#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    int w, d, tot;
    cin >> w >> d >> tot;

    int right_tot = w * (n - 1) * n / 2;
    if (right_tot == tot) {
      cout << n << '\n';
    } else {
      int diff = right_tot - tot;
      cout << diff / d << '\n';
    }
  }
}
