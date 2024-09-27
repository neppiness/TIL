#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int x; cin >> x;
  cout << x / 100 * 78 << ' ' << x / 100 * 80 + x  / 100 * 20 * 78 / 100;
}
