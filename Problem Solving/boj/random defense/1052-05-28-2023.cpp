#include <bits/stdc++.h>
using namespace std;

const int lgmx = 25;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k; cin >> n >> k;

  int m = n;
  int cnt = 0;
  for (int lg = 0; lg < lgmx; lg++) {
    int chk = (1 << lg);
    if (m & chk) cnt++;
  }

  int diff = cnt - k;
  int sum = 0;
  if (diff <= 0) { cout << 0; return 0; }
  while (diff > 0) {
    for (int lg = 0; lg < lgmx; lg++) {
      int chk = (1 << lg);
      if (!(m & chk)) continue;
      m += chk; break;
    }
    cnt = 0;
    for (int lg = 0; lg < lgmx; lg++) {
      int chk = (1 << lg);
      if ((m & chk)) cnt++;
    }
    diff = cnt - k;
  }
  cout << m - n;
}