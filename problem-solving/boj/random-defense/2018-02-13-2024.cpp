#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int cnt = 0;
  int m = 4480;
  while (--m) {
    int num = 2 * n + m - m * m;
    if (num <= 0) continue;
    int den = 2 * m;
    cnt += (num % den == 0);
  }
  cout << cnt;
}

