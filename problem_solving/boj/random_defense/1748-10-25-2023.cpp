#include <bits/stdc++.h>
using namespace std;

long long solve(int digit, int no) {
  if (digit == 0) return 0;
  int d_max = 1;
  for (int i = 0; i < digit; i++)
    d_max *= 10;
  int d_min = d_max / 10;

  long long ans = 0;
  if (no >= d_min) {
    ans += (min(d_max - 1, no) - d_min + 1) * digit;
  }
  return solve(digit - 1, no) + ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  cout << solve(9, n);
}
