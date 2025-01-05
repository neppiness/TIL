#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    int x; cin >> x;
    int d = x / 5;
    int r = x % 5;
    while (d--) cout << "++++ ";
    while (r--) cout << "|";
    cout << '\n';
  }
}
