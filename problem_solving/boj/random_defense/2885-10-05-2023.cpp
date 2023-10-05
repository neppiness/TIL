#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;

  int min_p = 21;
  int max_p = 0;
  for (int p = 0; p <= 20; p++) {
    int b = (1 << p);
    if (n & b) min_p = min(min_p, p);
    if (n <= b) {
      max_p = max(max_p, p);
      break;
    }
  }
  cout << (1 << max_p) << ' ' << (max_p - min_p);
}
