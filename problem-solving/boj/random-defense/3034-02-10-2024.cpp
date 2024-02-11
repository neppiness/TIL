#include <bits/stdc++.h>
using namespace std;

int t, w, h, x;

bool solve() {
  cin >> x;
  return x * x <= h * h + w * w;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t >> w >> h;
  while (t--) {
    if (solve()) cout << "DA\n";
    else cout << "NE\n";
  }
}
