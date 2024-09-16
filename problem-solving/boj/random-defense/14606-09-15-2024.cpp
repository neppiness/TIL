#include <bits/stdc++.h>
using namespace std;

int solve(int x) {
  if (x == 1) return 0;
  if (x % 2) {
    return x / 2 * (x / 2 + 1) + solve(x / 2) + solve(x / 2 + 1);
  }
  return x / 2 * x / 2 + 2 * solve(x / 2);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  cout << solve(n);
}
