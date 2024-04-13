#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  if (n == 1) {
    cout << 0; return 0;
  }

  int max_div = 1;
  for (int min_div = 2; min_div * min_div <= n; min_div++) {
    if (n % min_div != 0) {
      continue;
    }
    max_div = n / min_div;
  }
  cout << n - max_div;
}
