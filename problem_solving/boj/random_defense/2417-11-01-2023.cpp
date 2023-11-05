#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  long long n; cin >> n;
  long long sq = sqrt(n);
  if (sq >= 1 && (sq - 1) * (sq - 1) >= n) cout << sq - 1;
  else if (sq * sq >= n) cout << sq;
  else cout << sq + 1;
}
