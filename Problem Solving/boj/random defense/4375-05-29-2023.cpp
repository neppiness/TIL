#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int solve(int x) {
  ll a = 1;
  int cnt = 1;
  while (a % x != 0) {
    a = a*10 + 1; cnt++;
  }
  return cnt;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cout << solve(27) << '\n';
  return 0;
  for (int i = 1; i <= 10000; i++) {
    if (i % 2 == 0 || i % 5 == 0) continue;
    cout << i << ' ' << solve(i) << endl;
  }
}