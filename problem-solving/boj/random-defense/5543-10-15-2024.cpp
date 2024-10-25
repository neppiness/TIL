#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int mn = 0x7f7f7f7f;
  for (int i = 0; i < 3; i++) {
    int x; cin >> x;
    mn = min(mn, x);
  }
  int mn2 = 0x7f7f7f7f;
  for (int i = 0; i < 2; i++) {
    int x; cin >> x;
    mn2 = min(mn2, x);
  }
  cout << mn + mn2 - 50;
}
